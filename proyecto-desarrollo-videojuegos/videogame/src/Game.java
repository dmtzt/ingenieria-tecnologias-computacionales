
import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.util.LinkedList;

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
    private Thread thread; // thread to create the game
    private boolean running; //to set the game
    private Player player;
    private LinkedList<Enemy> enemies;
    private KeyManager keyManager;
    
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
        enemies = new LinkedList();
        //(rand() b-a+1)+a, es un rango de 3-8, b=8, a=3
        int random = (int) (Math.random() * 6) + 3;
        for (int i = 1; i <= random; i++) {
            Enemy enemy = new Enemy((int) (Math.random() * getWidth()) - 100, -100, 1, 100, 100, this);
            enemies.add(enemy);
        }

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

        long lastTime = System.nanoTime();
        System.out.println("Valor de running: " + running);
        while (running) {
            now = System.nanoTime();

            delta += (now - lastTime) / timeTick;

            lastTime = now;

            if (delta >= 1) {
                tick();
                render();
                delta--;
            }
        }
        stop();
    }

    public void tick() {
        keyManager.tick();
        player.tick();
        for (Enemy enemy : enemies) {
            enemy.tick();
            if (player.collision(enemy)) {
                player.setX(0);
                player.setY(getHeight() - 100);
                for (Enemy enem: enemies){
                    enem.setX((int) (Math.random() * getWidth()) - 100);
                    enem.setY(0);                
                }
            }
            continue;
        }
    }

    private void render() {
        bs = display.getCanvas().getBufferStrategy();

        if (bs == null) {
            display.getCanvas().createBufferStrategy(3);
        } else {
            g = bs.getDrawGraphics();
            g.drawImage(Assets.background, 0, 0, width, height, null);
            player.render((g));
            for (Enemy enemy : enemies) {
                enemy.render((g));
            }
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
}
