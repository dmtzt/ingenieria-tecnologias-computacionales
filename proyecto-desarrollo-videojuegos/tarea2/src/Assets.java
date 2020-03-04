
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
    public static BufferedImage taxFile;
    public static void init() {
        background = ImageLoader.loadImage("/images/background.jpg");
        player = ImageLoader.loadImage("/images/uncle-rich.png");
        taxFile = ImageLoader.loadImage("images/tax.png");
    }
}
