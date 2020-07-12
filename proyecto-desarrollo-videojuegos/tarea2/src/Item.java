
import java.awt.Graphics;
import java.awt.Rectangle;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author david
 */
public abstract class Item {
    protected static final int X_TOLERANCE = 10;
    protected static final int Y_TOLERANCE = 10;
    protected int x;
    protected int y;
    protected int width;
    protected int height;

    public Item(int x, int y, int width, int height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public abstract void tick();

    public abstract void render(Graphics g);

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }
    
    public void setY(int y) {
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public void setHeight(int height) {
        this.height = height;
    }
    
    //para checar si hay colision entre enemy y player
    public boolean collision(Object o){
        if(o instanceof Item){
            Rectangle recThis= new Rectangle (getX(), getY(), getWidth(), getHeight());
            //Its an object and you transform it that way to change it into an item
            Item item = (Item) o;
            Rectangle recOther= new Rectangle (item.getX(), item.getY(), item.getWidth(), item.getHeight());
            
            // If both rectangles intersect
            if (recThis.intersects(recOther)) {
                // If the intersection occurs between x and y tolerance values, it is valid
                if (Math.abs(getX() - item.getX()) < X_TOLERANCE && Math.abs(getY() - item.getY()) > Y_TOLERANCE)
                    return true;
            }
        }   
        return false;
    }
}
