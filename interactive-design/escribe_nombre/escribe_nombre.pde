/*
 * escribe_nombre
 * 
 * Permite que el usuario escriba con el mouse en una ventana en blanco.
 * Mientras el usuario desliza el mouse, el color de dibujo cambia si lo hace
 * con el boton izquierdo y borra si lo hace con el derecho.
 *
 * David Alejandro Martinez Tristan
 * 28/02/2019
 */

int weight;
float r, g, b;

void setup()
{
  // Valores iniciales
  weight = 10;
  // Color RGB blanco al dibujar
  r = 255;
  g = 255;
  b = 255;
  strokeWeight(weight);
  // Fondo blanco para la ventana
  background(255, 255, 255);
  // Tamano de la ventana
  size(800, 800);
}

void draw()
{
  // Asignar valores actuales de RGB al color del punto por dibujar
  stroke(r, g, b);
  // Definir ancho actual al punto por dibujar
  strokeWeight(weight);
  // Dibujar/borrar
  mousePressed();
  // Actualizar entrada del boton
  mouseClicked();
}

void mouseClicked()
{
  // Si el boton izquierdo es presionado, configurar valores para dibujar
  if (mouseButton == LEFT)
  {
    // Generar valores RGB aleatorios para crear colores diferentes
    r = random(255);
    g = random(255);
    b = random(255);
    // Definir un ancho del punto menor
    weight = 10;
  }
  // Si el boton derecho es presionado, configurar valores para borrar
  else if (mouseButton == RIGHT)
  {
    // Asignar valores RGB correspondientes al blanco
    r = 255;
    g = 255;
    b = 255;
    // Definir un ancho del punto mayor
    weight = 25;
  }
}

// Si el mouse es arrastrado mientras un boton es presionado, dibujar
void mouseDragged()
{
  point(mouseX, mouseY);  
}
