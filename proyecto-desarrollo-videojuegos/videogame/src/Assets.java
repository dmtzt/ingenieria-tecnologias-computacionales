
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
    public static BufferedImage enemy;
    public static void init() {
        background = ImageLoader.loadImage("/images/background.jpg");
        player = ImageLoader.loadImage("/images/cheems.png");
        enemy = ImageLoader.loadImage("images/sanic.png");
    }
}
