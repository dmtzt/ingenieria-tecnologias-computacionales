
import java.awt.Graphics;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author david
 */
public class Player extends Item {
    protected int direction;
    protected int width;
    protected int height;
    protected int lives;
    private Game game;
    private static int SPEED = 2;
    private static int LIVES = 5;
    
    public Player(int x, int y, int direction, int width, int height, Game game) {
        super(x, y, width, height);
        this.direction = direction;
        this.width = width;
        this.height = height;
        this.game = game;
        this.lives = LIVES;
    }
    
    public void setDirection(int direction) {
        this.direction = direction;
    }

    public int getHeight() {
        return height;
    }

    public int getWidth() {
        return width;
    }

    public int getDirection() {
        return direction;
    }
    
    public int getLives() {
        return lives;
    }
    
    public void setLives(int lives) {
        this.lives = lives;
    }

    @Override
    public void tick() {
        if (game.getKeyManager().up) {
            setY(getY() - SPEED);
        }
        if (game.getKeyManager().down) {
            setY(getY() + SPEED);
        }
        if (game.getKeyManager().left) {
            setX(getX() - SPEED);
        }
        if (game.getKeyManager().right) {
            setX(getX() + SPEED);
        }
        if (getX() + 60 >= game.getWidth()) {
            setX(game.getWidth() - 60);
        }
        else if (getX() <= -30) {
            setX(-30);
        }
        if (getY() + 80 >= game.getHeight()) {
            setY(game.getHeight() - 80);   
        }
        else if (getY() <= -20) {
            setY(-20);
        }
    }

    @Override
    public void render(Graphics g) {
        g.drawImage(Assets.player, getX(), getY(), getWidth(), getHeight(), null);
    }
    
}
