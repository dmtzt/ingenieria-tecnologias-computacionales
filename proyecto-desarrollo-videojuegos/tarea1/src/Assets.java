
import java.awt.image.BufferedImage;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author david
 */
public class Assets {
    public static BufferedImage background;
    public static BufferedImage player;
    public static BufferedImage cheems;
    public static BufferedImage stonks;
    public static void init() {
        background = ImageLoader.loadImage("/images/background.jpg");
        cheems = ImageLoader.loadImage("/images/cheems.png");
        stonks = ImageLoader.loadImage( "/images/stonks.png");
    }
    
    public static void setPlayerImage(boolean imageSwitch) {
        if (imageSwitch)
            player = stonks;
        else
            player = cheems;
    }
}
