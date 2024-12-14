#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>
#include <iostream>

using namespace sf;
int enemigosDerrotados = 0;
int vidas = 3;
int puntos = 0;

class Enemigos {
private:
	Sprite spriteEnemigo; 

public:
	Enemigos(Texture& textureArriba, Texture& textureAbajo, Texture& textureMedio) {
		int posXY = rand() % 5 + 1;

		if (posXY == 1 || posXY == 2) { 
			spriteEnemigo.setTexture(textureArriba);
		}
		else if (posXY == 3 || posXY == 4) {
			spriteEnemigo.setTexture(textureAbajo);
		}
		else {
			spriteEnemigo.setTexture(textureMedio);
		}
		spriteEnemigo.setScale(3.0, 3.0);
		switch (posXY) {
		case 1:
			spriteEnemigo.setPosition(77, 88);
			break;
		case 2:
			spriteEnemigo.setPosition(524, 88);
			break;
		case 3:
			spriteEnemigo.setPosition(51, 340);
			break;
		case 4:
			spriteEnemigo.setPosition(548, 340);
			break;
		case 5:
			spriteEnemigo.setPosition(338, 330);
			break;
		}
	}

	void draw(RenderWindow& window) {
		
		window.draw(spriteEnemigo);
		
	}
	// Verifica si el enemigo fue clickeado
	bool checkClick(int mouseX, int mouseY) {
		bool clickeado = spriteEnemigo.getGlobalBounds().contains(mouseX, mouseY);
		if (clickeado) {
			enemigosDerrotados++;
			puntos++;
			std::cout << "le diste a: "<<enemigosDerrotados << std::endl;
			std::cout << "puntos: " << puntos << std::endl;
		}
		
		return clickeado;
	}
};

class Inocente {
private:
	Sprite spriteInocente;
	 
public:
	Inocente(Texture& textureArriba, Texture& textureAbajo, Texture& textureMedio) {
		int posXY = rand() % 5 + 1;

		if (posXY == 1 || posXY == 2) {
			spriteInocente.setTexture(textureArriba);
		}
		else if (posXY == 3 || posXY == 4) {
			spriteInocente.setTexture(textureAbajo);
		}
		else {
			spriteInocente.setTexture(textureMedio);
		}
		spriteInocente.setScale(3.0, 3.0);
		switch (posXY) {
		case 1:
			spriteInocente.setPosition(77, 88);
			break;
		case 2:
			spriteInocente.setPosition(524, 88);
			break;
		case 3:
			spriteInocente.setPosition(51, 340);
			break;
		case 4:
			spriteInocente.setPosition(548, 340);
			break;
		case 5:
			spriteInocente.setPosition(338, 330);
			break;
		}
	}

	void draw(RenderWindow& window) {
	
			window.draw(spriteInocente);

		
	}
	// Verifica si el enemigo fue clickeado
	bool checkClick(int mouseX, int mouseY) {
		bool clickeado = spriteInocente.getGlobalBounds().contains(mouseX, mouseY);
		if (clickeado) {
			vidas--;
			puntos--;
			std::cout << "Le diste a un inocente" <<std::endl<< "Tus vidas son: " << vidas << std::endl;
			std::cout << "se resta un punto: " << puntos << std::endl;
		}
		return clickeado;
	}
};

class Numeros {
private:	
	sf::Texture textureCERO;
	sf::Sprite spriteCERO;
	sf::Texture textureUNO;
	sf::Sprite spriteUNO;
	sf::Texture textureDOS;
	sf::Sprite spriteDOS;
	sf::Texture textureTRES;
	sf::Sprite spriteTRES;
	sf::Texture textureCUATRO;
	sf::Sprite spriteCUATRO;
	sf::Texture textureCINCO;
	sf::Sprite spriteCINCO;
	sf::Texture textureSEIS;
	sf::Sprite spriteSEIS;
	sf::Texture textureSIETE;
	sf::Sprite spriteSIETE;
	sf::Texture textureOCHO;
	sf::Sprite spriteOCHO;
	sf::Texture textureNUEVE;
	sf::Sprite spriteNUEVE;
	sf::Texture textureDIEZ;
	sf::Sprite spriteDIEZ;

	sf::Vector2f posicion; // Posición de los números

public:
	Numeros() {
		
		textureCERO.loadFromFile("CERO.png");
		textureUNO.loadFromFile("UNO.png");
		textureDOS.loadFromFile("DOS.png");
		textureTRES.loadFromFile("TRES.png");
		textureCUATRO.loadFromFile("CUATRO.png");
		textureCINCO.loadFromFile("CINCO.png");
		textureSEIS.loadFromFile("SEIS.png");
		textureSIETE.loadFromFile("SIETE.png");
		textureOCHO.loadFromFile("OCHO.png");
		textureNUEVE.loadFromFile("NUEVE.png");
		textureDIEZ.loadFromFile("DIEZ.png");

		spriteCERO.setTexture(textureCERO);
		spriteUNO.setTexture(textureUNO);
		spriteDOS.setTexture(textureDOS);
		spriteTRES.setTexture(textureTRES);
		spriteCUATRO.setTexture(textureCUATRO);
		spriteCINCO.setTexture(textureCINCO);
		spriteSEIS.setTexture(textureSEIS);
		spriteSIETE.setTexture(textureSIETE);
		spriteOCHO.setTexture(textureOCHO);
		spriteNUEVE.setTexture(textureNUEVE);
		spriteDIEZ.setTexture(textureDIEZ);

		// Posición inicial por defecto
		posicion = sf::Vector2f(0, 0);
		actualizarPosiciones();
	}

	// Método para dibujar el número actual
	void dibujar(sf::RenderWindow& ventana, int valor) {
		switch (valor) {
		case -3:
			ventana.draw(spriteCERO);
			break;
		case -2:
			ventana.draw(spriteCERO);
			break;
		case -1:
			ventana.draw(spriteCERO);
			break;
		case 0:
			ventana.draw(spriteCERO);
			break;
		case 1:
			ventana.draw(spriteUNO);
			break;
		case 2:
			ventana.draw(spriteDOS);
			break;
		case 3:
			ventana.draw(spriteTRES);
			break;
		case 4:
			ventana.draw(spriteCUATRO);
			break;
		case 5:
			ventana.draw(spriteCINCO);
			break;
		case 6:
			ventana.draw(spriteSEIS);
			break;
		case 7:
			ventana.draw(spriteSIETE);
			break;
		case 8:
			ventana.draw(spriteOCHO);
			break;
		case 9:
			ventana.draw(spriteNUEVE);
			break;
		case 10:
			ventana.draw(spriteDIEZ);
			break;
		}
		
	}

	// Cambiar la posición de todos los sprites
	void setPosicion(float x, float y) {
		posicion = sf::Vector2f(x, y);
		actualizarPosiciones();
	}

private:
	// Actualiza las posiciones de los sprites
	void actualizarPosiciones() {
		spriteCERO.setPosition(posicion);
		spriteUNO.setPosition(posicion);
		spriteDOS.setPosition(posicion);
		spriteTRES.setPosition(posicion);
		spriteCUATRO.setPosition(posicion);
		spriteCINCO.setPosition(posicion);
		spriteSEIS.setPosition(posicion);
		spriteSIETE.setPosition(posicion);
		spriteOCHO.setPosition(posicion);
		spriteNUEVE.setPosition(posicion);
		spriteDIEZ.setPosition(posicion);
	}
};


Event evt;
Texture textureFondo;
Texture texture;
Texture texturePantallaPrincipal;
Texture textureDisparo;
Texture textureGanaste;
Texture texturePerdiste;
Sprite spritePantallaPrincipal;
Sprite sprite;
Sprite spriteFondo;
Sprite spriteDisparo;
Sprite spriteGanaste;
Sprite spritePerdiste;
Numeros numerosVida;
Numeros numerosPuntos;
Numeros numerosDerrotados;

int main() {
	srand(time(0));

	////ENEMIGO 1
	Texture textureEnemigo1Arriba;
	textureEnemigo1Arriba.loadFromFile("ENEMIGO1ARRIBA.png");
	Texture textureEnemigo1Abajo;
	textureEnemigo1Abajo.loadFromFile("ENEMIGO1ABAJO.png");
	Texture textureEnemigo1Medio;
	textureEnemigo1Medio.loadFromFile("ENEMIGO1MEDIO.png");

	//ENEMIGO 2
	Texture textureEnemigo2Arriba;
	textureEnemigo2Arriba.loadFromFile("ENEMIGO2ARRIBA.png");
	Texture textureEnemigo2Abajo;
	textureEnemigo2Abajo.loadFromFile("ENEMIGO2ABAJO.png");
	Texture textureEnemigo2Medio;
	textureEnemigo2Medio.loadFromFile("ENEMIGO2MEDIO.png");

	//INOCENTE
	Texture textureInocenteArriba;
	textureInocenteArriba.loadFromFile("INOCENTEARRIBA.png");
	Texture textureInocenteAbajo;
	textureInocenteAbajo.loadFromFile("INOCENTEABAJO.png");
	Texture textureInocenteMedio;
	textureInocenteMedio.loadFromFile("INOCENTEMEDIO.png");

	texturePantallaPrincipal.loadFromFile("PantallaPrincipal.png");
	spritePantallaPrincipal.setTexture(texturePantallaPrincipal);

	textureFondo.loadFromFile("FONDO.png");
	spriteFondo.setTexture(textureFondo);

	texture.loadFromFile("crosshair.png");
	sprite.setTexture(texture);

	textureDisparo.loadFromFile("disparo.png");
	spriteDisparo.setTexture(textureDisparo);

	textureGanaste.loadFromFile("ganaste.png");
	spriteGanaste.setTexture(textureGanaste);

	texturePerdiste.loadFromFile("perdiste.png");
	spritePerdiste.setTexture(texturePerdiste);


	sprite.setPosition(336, 236);
	spriteDisparo.setPosition(150, 80);
	numerosVida.setPosicion(150, 10);
	numerosPuntos.setPosicion(400, 10);
	numerosDerrotados.setPosicion(730, 10);

	sprite.setScale(0.5, 0.5);
	spriteFondo.setScale(3.1, 3.1);
	spritePantallaPrincipal.setScale(3.1, 3.1);
	spriteGanaste.setScale(3.1, 3.1);
	spritePerdiste.setScale(3.1, 3.1);

	//Creamos la ventana
	RenderWindow App(VideoMode(800, 620, 32), "El pistolero");

	App.setMouseCursorVisible(false);

	bool enPantallaInicial = true;
	bool esEnemigo1 = rand() % 2 == 0;  // 0 para Enemigo 1, 1 para Enemigo 2

	Texture* textureEnemigoArriba;
	Texture* textureEnemigoAbajo;
	Texture* textureEnemigoMedio;

	if (esEnemigo1) {
		textureEnemigoArriba = &textureEnemigo1Arriba;
		textureEnemigoAbajo = &textureEnemigo1Abajo;
		textureEnemigoMedio = &textureEnemigo1Medio;
	}
	else {
		textureEnemigoArriba = &textureEnemigo2Arriba;
		textureEnemigoAbajo = &textureEnemigo2Abajo;
		textureEnemigoMedio = &textureEnemigo2Medio;
	}

	Enemigos enemigo(*textureEnemigoArriba, *textureEnemigoAbajo, *textureEnemigoMedio);
	Inocente inocente(textureInocenteArriba, textureInocenteAbajo, textureInocenteMedio);

	Clock relojPersonaje;
	Clock relojDisparo;
	bool disparoActivo = false;
	bool personajeActivo = true; // Indica si hay un personaje en pantalla
	int tipoEntidadActual = rand() % 3; // 0: Enemigo1, 1: Enemigo2, 2: Inocente
	bool juegoTerminado = false;

	while (App.isOpen())
	{
		
				while (App.pollEvent(evt)) {
					switch (evt.type) {

					case sf::Event::Closed:
						App.close();
						break;

					case sf::Event::MouseMoved:
						sprite.setPosition(evt.mouseMove.x, evt.mouseMove.y);
						break;

					case sf::Event::KeyPressed:
						if (evt.key.code == sf::Keyboard::Escape) {
							App.close(); 
						}

						if (juegoTerminado && evt.key.code == sf::Keyboard::Enter) {
							// Reiniciar el juego si el jugador presiona Enter
							vidas = 3;
							enemigosDerrotados = 0;
							puntos = 0;
							enPantallaInicial = true;
							personajeActivo = false;
							juegoTerminado = false;
							relojPersonaje.restart();
						}
						break;
					}

					if (evt.type == sf::Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Left) {
						if (enPantallaInicial) {
							enPantallaInicial = false;
							personajeActivo = false;
							relojPersonaje.restart();
						}
						// Verificar clic en el enemigo
						else {
							bool acierto = false;
							if ((tipoEntidadActual == 0 || tipoEntidadActual == 1) &&
								enemigo.checkClick(evt.mouseButton.x, evt.mouseButton.y)) {

								acierto = true;
								personajeActivo = false; // Desactiva el personaje
								relojPersonaje.restart();


							}

							else if (tipoEntidadActual == 2 &&
								inocente.checkClick(evt.mouseButton.x, evt.mouseButton.y)) {
								acierto = true;
								personajeActivo = false; // Desactiva el personaje
								relojPersonaje.restart();

							}
							if (!acierto) {
								disparoActivo = true;
								relojDisparo.restart();
							}
						}
					}
				}
				
				// Manejar desaparición automática del personaje
				if (!juegoTerminado && !enPantallaInicial && personajeActivo && relojPersonaje.getElapsedTime().asSeconds() >= 2) {

					personajeActivo = false; // Desactiva el personaje

					if (tipoEntidadActual == 0 || tipoEntidadActual == 1) {

						vidas--; // Penalización si es un enemigo
						std::cout << "Se resta una vida." << std::endl;
						disparoActivo = true;
						relojDisparo.restart();
					}
				}

				if (!personajeActivo) {
					tipoEntidadActual = rand() % 3; // Selecciona aleatoriamente el nuevo tipo de personaje
					if (tipoEntidadActual == 0) {
						enemigo = Enemigos(textureEnemigo1Arriba, textureEnemigo1Abajo, textureEnemigo1Medio);
					}
					else if (tipoEntidadActual == 1) {
						enemigo = Enemigos(textureEnemigo2Arriba, textureEnemigo2Abajo, textureEnemigo2Medio);
					}
					else if (tipoEntidadActual == 2) {
						inocente = Inocente(textureInocenteArriba, textureInocenteAbajo, textureInocenteMedio);
					}
					personajeActivo = true; // Reactiva el personaje
					relojPersonaje.restart();
				}

				if (juegoTerminado) {
					
					// Si el juego terminó, no hacer más lógica de personajes
					App.clear();
					App.draw(spriteFondo);
					if (vidas <= 0) {
						App.draw(spritePerdiste);
					}
					else if (enemigosDerrotados >= 10) {
						App.draw(spriteGanaste); // Dibuja la imagen de "Ganaste"
					}
					numerosVida.dibujar(App, vidas);
					numerosPuntos.dibujar(App, puntos);
					numerosDerrotados.dibujar(App, enemigosDerrotados);
					App.display();
					continue; // Salta el resto del ciclo de juego
				}
		App.clear();

		if (vidas <= 0) {
			App.draw(spritePerdiste);
			juegoTerminado = true;
		}
		else if (enemigosDerrotados >= 10) {
			App.draw(spriteGanaste); 
			juegoTerminado = true;
		}

		if (enPantallaInicial) {
			App.draw(spritePantallaPrincipal);
	
		}
		else {
			App.draw(spriteFondo);
			numerosVida.dibujar(App, vidas);
			numerosPuntos.dibujar(App, puntos);
			numerosDerrotados.dibujar(App, enemigosDerrotados);
			// Dibuja el personaje si está activo
			if (personajeActivo) {
				if (tipoEntidadActual == 0 || tipoEntidadActual == 1) {
					enemigo.draw(App); // Dibuja el enemigo
				}
				else if (tipoEntidadActual == 2) {
					inocente.draw(App); // Dibuja el inocente
				}
			}

			App.draw(sprite);

			if (disparoActivo) {
				App.draw(spriteDisparo); // Dibuja el disparo
				if (relojDisparo.getElapsedTime().asSeconds() >= 1) {
					disparoActivo = false; // Desactiva el disparo tras 1 segundo
				}
			}
		}
		
		App.display();
	}

	return 0;
}