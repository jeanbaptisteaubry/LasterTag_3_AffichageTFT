
/*****************************************************

  On dessine sur un écran TFT KMR-1.8 SPI
  Version pour ESP8266 / ESP32
  
  Plus d'infos:
  https://electroniqueamateur.blogspot.com/2019/08/ecran-couleur-spi-st7735-et-esp32.html

  Les couleurs prédéfinies par la bibliothèque sont:

  TFT_BLACK      TFT_NAVY         TFT_DARKGREEN     TFT_DARKCYAN
  TFT_MAROON     TFT_PURPLE       TFT_OLIVE         TFT_LIGHTGREY
  TFT_DARKGREY   TFT_BLUE         TFT_GREEN         TFT_CYAN
  TFT_RED        TFT_MAGENTA      TFT_YELLOW        TFT_WHITE
  TFT_ORANGE     TFT_GREENYELLOW  TFT_PINK

*****************************************************/

#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI ecran = TFT_eSPI();


void setup() {
  ecran.init();
  ecran.setRotation(1); // réglage de l'écran en mode paysage (0 pour mode portrait)
  randomSeed(analogRead(A0)); // pour la génération de nombres aléatoires
}

void loop() {

  // compte à rebours

  // fond vert
  ecran.fillScreen(TFT_GREEN); 
 
  // texte pourpre sur fond vert
  // puisqu'on a spécifié une couleur de fond, le texte
  // masquera ce qui était écrit prédécemment
  ecran.setTextColor(TFT_PURPLE, TFT_GREEN);

  // on écrit "5", à la position x = 80, y = 35, avec la police #7
  ecran.drawCentreString("5", 80, 35, 7); 
  delay(500);
  ecran.drawCentreString("4", 80, 35, 7); 
  delay(500);
  ecran.drawCentreString("3", 80, 35, 7); 
  delay(500);
  ecran.drawCentreString("2", 80, 35, 7); 
  delay(500);
  ecran.drawCentreString("1", 80, 35, 7); 
  delay(500);

  // présentation des 4 polices de caractère (2, 4, 6 et 7)
  // 6 et 7 ne comportent que des chiffres

  ecran.fillScreen(TFT_WHITE); // fond blanc
  ecran.setTextColor(TFT_BLACK); // texte noir
  ecran.drawString("123", 20, 25, 2); // police #2
  delay(500);
  ecran.setTextColor(TFT_DARKGREEN); // texte vert
  ecran.drawString("123", 10, 70, 4);  // police #4
  delay(500);
  ecran.setTextColor(TFT_BLUE); // texte bleu
  ecran.drawString("123", 60, 10, 6); // police #6: chiffres seulement
  delay(500);
  ecran.setTextColor(TFT_RED ); // texte rouge
  ecran.drawString("123", 50, 60, 7); // police #7: chiffres seulement
  delay(500);

  // formes géométriques simples

  ecran.fillScreen(TFT_BLACK); // fond noir

  ecran.drawLine(5, 64, 155, 64, TFT_YELLOW);  // ligne horizontale à y = 64
  ecran.drawLine(80, 5, 80, 123, TFT_YELLOW);  // ligne verticale à x = 80
  delay(500);

  // contour d'un rectangle x= 15, y = 5, largeur = 50, hauteur = 50, couleur vert
  ecran.drawRect( 15, 5, 50, 50, TFT_GREENYELLOW); 
  delay(500);
  // contour d'un cercle: x = 120, y = 30, rayon = 25, couleur orange
  ecran.drawCircle(120, 30, 25, TFT_ORANGE); 
  delay(500);
  // contour de rectangle à coins arrondis x = 8, y = 80, largeur = 60, hauteur = 30, rayon du coin = 5, couleur rose
  ecran.drawRoundRect(8, 80, 60, 30, 5, TFT_PINK);  // contour d'un rectangle à coins arrondis
  delay(500);
  // contour de triangle x1 = 120 y1 = 70 x2 = 90 y2 = 120 x3 = 150 y3 = 120 couleur cyan
  ecran.drawTriangle(120, 70, 90, 120, 150, 120, TFT_CYAN);
  delay(500);

  // même chose, mais avec des formes pleines plutôt que des contours.
  ecran.fillRect( 15, 5, 50, 50, TFT_GREENYELLOW); 
  delay(500);
  ecran.fillCircle(120, 30, 25, TFT_ORANGE); 
  delay(500);
  ecran.fillRoundRect(8, 80, 60, 30, 5, TFT_PINK);  
  delay(500);
  ecran.fillTriangle(120, 70, 90, 120, 150, 120, TFT_CYAN);  

  delay(500);

  ecran.fillScreen(TFT_YELLOW);

  // on trace des points au hasard
  for (int i = 1; i < 10000; i++) {
    int x = random(159);
    int y = random(127);
    ecran.drawPixel(x, y, TFT_BLACK);  // draw pixel: un seul point
    delay(1);
  }

}