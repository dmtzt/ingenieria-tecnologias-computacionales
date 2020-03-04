
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

    private static final int UP = 1;
    private static final int DOWN = 2;
    private static final int LEFT = 3;
    private static final int RIGHT = 4;
    private static final int INITIAL_SPEED = 0;
    private static final int ACCELERATION = 1;
    private static final int MAX_SPEED = 10;

    protected int width;
    protected int height;
    protected int speed;
    protected int direction;
    protected boolean upToggle;
    protected boolean downToggle;
    protected boolean leftToggle;
    protected boolean rightToggle;
    private Game game;

    public Player(int x, int y, int width, int height, Game game) {
        super(x, y, width, height);
        this.width = width;
        this.height = height;
        this.game = game;
        this.speed = INITIAL_SPEED;
        this.upToggle = false;
        this.downToggle = false;
        this.leftToggle = false;
        this.rightToggle = false;
        this.direction = RIGHT;
    }

    public void setDirection(int direction) {
        this.direction = direction;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public void setUpToggle(boolean upToggle) {
        this.upToggle = upToggle;
    }

    public void setDownToggle(boolean downToggle) {
        this.downToggle = downToggle;
    }

    public void setLeftToggle(boolean leftToggle) {
        this.leftToggle = leftToggle;
    }

    public void setRightToggle(boolean rightToggle) {
        this.rightToggle = rightToggle;
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

    public int getSpeed() {
        return speed;
    }

    public boolean getUpToggle() {
        return upToggle;
    }

    public boolean getDownToggle() {
        return downToggle;
    }

    public boolean getLeftToggle() {
        return leftToggle;
    }

    public boolean getRightToggle() {
        return rightToggle;
    }

    @Override
    public void tick() {
        if (game.getKeyManager().up) {
            // One-time-only-actions
            if (!getUpToggle()) {
                // Activate key toggle
                setUpToggle(true);
                // If the direction is up, accelerate
                if (getDirection() == UP && getSpeed() < MAX_SPEED) {
                    setSpeed(getSpeed() + ACCELERATION);
                } // If the direction is down
                else if (getDirection() == DOWN) {
                    // If the deceleration stops the player, only change direction
                    if (getSpeed() - ACCELERATION <= INITIAL_SPEED) {
                        setDirection(UP);
                    } // Else, decelerate
                    else {
                        setSpeed(getSpeed() - ACCELERATION);
                    }
                } else if (getDirection() == LEFT || getDirection() == RIGHT) {
                    setDirection(UP);
                }
            }
        } else {
            setUpToggle(false);
        }

        if (game.getKeyManager().down) {
            // One-time-only-actions
            if (!getDownToggle()) {
                // Activate key toggle
                setDownToggle(true);
                // If the direction is down, accelerate
                if (getDirection() == DOWN && getSpeed() < MAX_SPEED) {
                    setSpeed(getSpeed() + ACCELERATION);
                } // If the direction is up
                else if (getDirection() == UP) {
                    // If the deceleration stops the player, only change direction
                    if (getSpeed() - ACCELERATION <= INITIAL_SPEED) {
                        setDirection(DOWN);
                    } // Else, decelerate
                    else {
                        setSpeed(getSpeed() - ACCELERATION);
                    }
                } else if (getDirection() == LEFT || getDirection() == RIGHT) {
                    setDirection(DOWN);
                }
            }
        } else {
            setDownToggle(false);
        }

        if (game.getKeyManager().left) {
            // One-time-only-actions
            if (!getLeftToggle()) {
                // Activate key toggle
                setLeftToggle(true);
                // If the direction is left, accelerate
                if (getDirection() == LEFT && getSpeed() < MAX_SPEED) {
                    setSpeed(getSpeed() + ACCELERATION);
                } // If the direction is right
                else if (getDirection() == RIGHT) {
                    // If the deceleration stops the player, only change direction
                    if (getSpeed() - ACCELERATION <= INITIAL_SPEED) {
                        setDirection(LEFT);
                    } // Else, decelerate
                    else {
                        setSpeed(getSpeed() - ACCELERATION);
                    }
                } else if (getDirection() == UP || getDirection() == DOWN) {
                    setDirection(LEFT);
                }
            }
        } else {
            setLeftToggle(false);
        }

        if (game.getKeyManager().right) {
            // One-time-only-actions
            if (!getRightToggle()) {
                // Activate key toggle
                setRightToggle(true);
                // If the direction is right, accelerate
                if (getDirection() == RIGHT && getSpeed() < MAX_SPEED) {
                    setSpeed(getSpeed() + ACCELERATION);
                } // If the direction is left
                else if (getDirection() == LEFT) {
                    // If the deceleration stops the player, only change direction
                    if (getSpeed() - ACCELERATION <= INITIAL_SPEED) {
                        setDirection(RIGHT);
                    } // Else, decelerate
                    else {
                        setSpeed(getSpeed() - ACCELERATION);
                    }
                } else if (getDirection() == UP || getDirection() == DOWN) {
                    setDirection(RIGHT);
                }
            }
        } else {
            setRightToggle(false);
        }

        switch (direction) {
            case UP:
                setY(getY() - speed);
                break;
            case DOWN:
                setY(getY() + speed);
                break;
            case LEFT:
                setX(getX() - speed);
                break;
            case RIGHT:
                setX(getX() + speed);
                break;
        }

        if (getX() + 60 >= game.getWidth()) {
            setX(game.getWidth() - 60);
            setDirection(LEFT);
        } else if (getX() <= -30) {
            setX(-30);
            setDirection(RIGHT);
        }
        if (getY() + 80 >= game.getHeight()) {
            setY(game.getHeight() - 80);
            setDirection(UP);
        } else if (getY() <= -20) {
            setY(-20);
            setDirection(DOWN);
        }
    }

    @Override
    public void render(Graphics g) {
        g.drawImage(Assets.player, getX(), getY(), getWidth(), getHeight(), null);
    }
}
