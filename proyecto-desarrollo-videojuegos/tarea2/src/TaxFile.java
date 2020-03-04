
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
    
    public TaxFile(int x, int y, int width, int height, Game game) {
        super(x, y, width, height);
        this.game = game;
    }

    @Override
    public void tick() {
        // moving enemy to follow player
        setY(getY() + 4);
        
    }

    @Override
    public void render(Graphics g) {
        g.drawImage(Assets.taxFile, getX(), getY(), getWidth(), getHeight(), null);
    }
}
