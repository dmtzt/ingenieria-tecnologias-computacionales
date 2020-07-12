
import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.util.LinkedList;
import java.util.Set;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author david
 */
public class Game implements Runnable {

    private BufferStrategy bs; // to have several buffers when displaying
    private Graphics g; // to opaint objects
    private Display display; // to display in the game
    String title; // title of the window
    private int width; // width of the window
    private int height; // height of the window
    private int collisionCounter;
    private int score;
    private int taxFileSpeed;
    private Thread thread; // thread to create the game
    private boolean running; //to set the game
    private boolean spawn;
    private boolean spawnControl;
    private boolean speedControl;
    private Player player;
    private LinkedList<TaxFile> taxFiles;
    private KeyManager keyManager;
    private static final long NANOSECS_TO_SECS = 1000000000;
    private static final int SPAWN_RATE = 4;
    private static final int WIDTH_OFFSET = 400;
    private static final int COLUMNS = 50;
    private static final int TAX_FILE_WIDTH = 80;
    private static final int TAX_FILE_HEIGHT = 80;
    private static final int SCORE_INCREMENT = 100;
    private static final int SCORE_DECREMENT = 20;
    private static final int X_SHIFT = 50;
    private static final int INITIAL_TAX_FILE_SPEED = 1;
    
    /**
     *
     * @param title
     * @param width
     * @param height
     */
    // Variables must be initialized in the constructor or an init() method
    public Game(String title, int width, int height) {
        this.title = title;
        this.width = width;
        this.height = height;
        running = false;
        keyManager = new KeyManager();
    }
    
    private void init() {
        display = new Display(title, getWidth(), getHeight());
        Assets.init();
        player = new Player(0, getHeight() - 100, 1, 100, 100, this);
        taxFiles = new LinkedList<>();
        //(rand() b-a+1)+a, es un rango de 3-8, b=8, a=3
        taxFileSpeed = INITIAL_TAX_FILE_SPEED;
        speedControl = false;
        collisionCounter = 0;
        score = 0;

        display.getJframe().addKeyListener(keyManager);
    }
    
    @Override
    public void run() {
        // The IDE creates a default exception when the method is added
        // The exception must be erased and the method completed
        init();

        int fps = 50;

        double timeTick = 1000000000 / fps;

        double delta = 0;

        long now;
        
        int seconds;
        
        boolean createTaxFiles = false;

        long lastTime = System.nanoTime();
        System.out.println("Valor de running: " + running);
        while (running) {
            now = System.nanoTime();

            delta += (now - lastTime) / timeTick;

            lastTime = now;
            
            // Cada taza de spawn, genera nuevos personajes
            seconds = (int) (System.nanoTime() / NANOSECS_TO_SECS);
            if (seconds % SPAWN_RATE == 0)
                setSpawn(true);            
            else
                setSpawn(false);

            if (delta >= 1) {
                tick(createTaxFiles);
                render();
                delta--;
            }
            
            if (player.getLives() < 0)
                break;
        }
        stop();
    }

    public void tick(boolean createTaxFiles) {
        if (getSpawn() && spawnControl == false) {
            // Genera 6-8 enemigos
            int random = (int) (Math.random() * 2) + 6;
            for (int i = 1; i <= random; i++) {
                // Asigna una posición inicial aleatoria en x
                int xPosTaxFile = (getWidth() + WIDTH_OFFSET)/ (int) (Math.random() * Math.random() * COLUMNS + 1) + X_SHIFT;
                // Inicializa la instancia y agrégala a la lista encadenada
                TaxFile taxFile = new TaxFile(xPosTaxFile, -TAX_FILE_HEIGHT, TAX_FILE_WIDTH, TAX_FILE_HEIGHT, taxFileSpeed, this);
                taxFiles.add(taxFile);
            }
            
            spawnControl = true;
        }
        else if (!getSpawn())
            spawnControl = false;
        
        keyManager.tick();
        player.tick();
        for (int i = 0; i < taxFiles.size(); i++) {
            taxFiles.get(i).tick();
            if (player.collision(taxFiles.get(i))) {
                taxFiles.remove(i);
                setScore(getScore() + SCORE_INCREMENT);
                
                for (TaxFile taxFile : taxFiles)
                    taxFile.setSpeed(getTaxFileSpeed());
            }
            else if (taxFiles.get(i).getY() - getHeight() > TAX_FILE_HEIGHT) {
                setScore(getScore() - SCORE_DECREMENT);
                collisionCounter++;
                
                if (collisionCounter > 9)
                {
                    player.setLives(player.getLives() - 1);
                    
                    if (speedControl == false)
                        setTaxFileSpeed(getTaxFileSpeed() + 1);
                    
                    speedControl = true;
                    collisionCounter = 0;
                    
                }
                taxFiles.remove(i);
            }
            else if (!speedControl)
                speedControl = false;
        }
        
        System.out.println(getTaxFileSpeed());
    }

    private void render() {
        bs = display.getCanvas().getBufferStrategy();

        if (bs == null) {
            display.getCanvas().createBufferStrategy(3);
        } else {
            g = bs.getDrawGraphics();
            g.drawImage(Assets.background, 0, 0, width, height, null);
            g.setColor(Color.white);
            g.drawString(("Score: " + Integer.toString(getScore())), 10, 50);
            g.drawString(("Lives: " + Integer.toString(player.getLives())), 10, 100);
            player.render((g));
            for (TaxFile taxFile : taxFiles) {
                taxFile.render((g));
            }
            
            if (player.getLives() == 0)
                g.drawString("GAME OVER", (getWidth() / 2 - 30), (getHeight() / 2));
            
            bs.show();
            g.dispose();
    
        }
    }

    // A synchronized method cannot be running at the same time than
    // another synchronized method
    public synchronized void start() {
        System.out.println("Estoy en el start");
        if (!running) {
            running = true;
            thread = new Thread(this);
            thread.start();
        }
    }

    public synchronized void stop() {
        if (running) {
            running = false;
            try {
                thread.join();
            } catch (InterruptedException ie) {
                ie.printStackTrace();
            }
        }
    }
    
    public void setSpawn(boolean spawn) {
        this.spawn = spawn;
    }
    
    public Player getPlayer() {
        return player;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public KeyManager getKeyManager() {
        return keyManager;
    }
    
    private boolean getSpawn() {
        return spawn;
    }
    
    public int getScore() {
        return score;
    }
    
    public void setScore(int score) {
        this.score = score;
    }
    
    public int getTaxFileSpeed() {
        return taxFileSpeed;
    }

    public void setTaxFileSpeed(int taxFileSpeed) {
        this.taxFileSpeed = taxFileSpeed;
    }
}
