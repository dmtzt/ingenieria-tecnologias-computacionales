
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
public class TaxFile extends Item{
    private Game game;
    private int speed;
    
    public TaxFile(int x, int y, int width, int height, int speed, Game game) {
        super(x, y, width, height);
        this.game = game;
        this.speed = speed;
    }

    @Override
    public void tick() {
        setY(getY() + speed);
        
    }

    @Override
    public void render(Graphics g) {
        g.drawImage(Assets.taxFile, getX(), getY(), getWidth(), getHeight(), null);
    }

    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }
}
