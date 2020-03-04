
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
public class Enemy extends Item{
    private int direction;
    private Game game;
    
    public Enemy(int x, int y, int direction, int width, int height, Game game) {
        super(x, y, width, height);
        this.direction = direction;
        this.game = game;
    }

    public int getDirection() {
        return direction;
    }


    public void setDirection(int direction) {
        this.direction = direction;
    }


    @Override
    public void tick() {
        // moving enemy to follow player
        if(this.getX() > game.getPlayer().getX()){
            setX(getX() - 1);
        } else{
            setX(getX() + 1);
        }
        if(this.getY() > game.getPlayer().getY()){
            setY(getY() - 1);
        } else{
            setY(getY() + 1);
        }        
        
    }

    @Override
    public void render(Graphics g) {
        g.drawImage(Assets.enemy, getX(), getY(), getWidth(), getHeight(), null);
    }
}
