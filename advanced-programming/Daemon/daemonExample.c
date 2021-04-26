#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

#define LOCK_FILE "Log.txt"

int exit_program = 0;

static void signal_handler(int signo)
{
    //syslog(LOG_NOTICE, "First daemon running. %d", signo );
    printf("Signal trigger %d", signo);
    exit_program = 1;
}

static int
lock_file(const char *const filepath, int fd)
{
    struct flock lock;
    int used = 0; /* Bits 0 to 2: stdin, stdout, stderr */
    if (fd == -1)
    {
        if (errno == EALREADY)
            errno = EIO;
        return errno;
    }
    while (1)
        if (fd == STDIN_FILENO)
        {
            used |= 1;
            fd = dup(fd);
        }
        else if (fd == STDOUT_FILENO)
        {
            used |= 2;
            fd = dup(fd);
        }
        else if (fd == STDERR_FILENO)
        {
            used |= 4;
            fd = dup(fd);
        }
        else
            break;

    /* Close the standard descriptors we temporarily used. */
    if (used & 1)
        close(STDIN_FILENO);
    if (used & 2)
        close(STDOUT_FILENO);
    if (used & 4)
        close(STDERR_FILENO);

    /* Did we run out of descriptors? */
    if (fd == -1)
        return errno = EMFILE;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        /* Lock failed. Close file and report locking failure. */
        close(fd);
        return errno = EALREADY;
    }
    return 0;
}

static void
unlink_file(char *path)
{
    if (unlink(path) < 0)
    {
        fprintf(stderr, "warning: unlinking '%s' failed: %s\n",
                path, strerror(errno));
    }
}

static void
unlock_file(int fd)
{
    if (flock(fd, LOCK_UN) < 0)
    {
        fprintf(stderr, "cannot unlock: %s\n", strerror(errno));
        exit(1);
    }
}


int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

static pid_t daemonize()
{
    pid_t pid;

    /* Fork off the parent process */
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* On success: The child process becomes session leader */
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    /* Catch, ignore and handle signals */

    /* Fork off for the second time*/
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* Set new file permissions */
    umask(027);

    /* Change the working directory to the root directory */
    /* or another appropriated directory */
    chdir("/Users/christian/progrAva");

    /* Close all open file descriptors */
    // int x;
    // for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
    // {
    //  //   close(x);
    // }

    /* Open the log file */
    openlog("firstdaemon", LOG_PID, LOG_DAEMON);
    return pid;
}

int main()
{
    printf("Starting daemonize\n");
    pid_t pid = daemonize();

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    int fd = 0;
    int sz;
    int result;

    if (exists(LOCK_FILE) == 0)
    {
        fd = open(LOCK_FILE, O_CREAT | O_RDWR, 0644);
        printf("Creating File \n");

        result = lock_file(LOCK_FILE, fd);
        if (result == 0)
        {
            while (exit_program == 0)
            {
                //TODO: Insert daemon code here.
                syslog(LOG_NOTICE, "First daemon running.");
                sz = write(fd, "Logging to file\n", strlen("Logging to file\n"));
                sleep(10);
            }
            close(fd);
            syslog(LOG_NOTICE, "First daemon terminated.");
            closelog();
            //unlock_file(fd);
            unlink_file(LOCK_FILE);
        }
        else if (result == EALREADY)
        {
            printf("Lock exists on file %s\n", LOCK_FILE);
            syslog(LOG_NOTICE, "First daemon Lock exists on file.");
            syslog(LOG_NOTICE, "First daemon terminated.");
            exit(0);
            return EXIT_SUCCESS;
        }
        else
        {
            /* Cannot lock YOUR_LOCKFILE_PATH, see strerror(result). */
            printf("Cannot place lock on file %s\n", LOCK_FILE);
            syslog(LOG_NOTICE, "First daemon cannot place Lock on file.");
            syslog(LOG_NOTICE, "First daemon terminated.");
            exit(0);
            return EXIT_SUCCESS;
        }
    }
    else
    {
        printf("Lock exists on file %s\n", LOCK_FILE);
        syslog(LOG_NOTICE, "First daemon Lock exists on file.");
        syslog(LOG_NOTICE, "First daemon terminated.");
        exit(0);
    }

    return EXIT_SUCCESS;
}
