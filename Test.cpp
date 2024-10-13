#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Header.h"

/*std::string Point::ToString() {
	std::stringstream sStream;
	sStream << "Point: x: " << x << ", y: " << y << ", z: " << z;
	return sStream.str();
}*/

float Vector2::GetX() {
	return m_x;
}

float Vector2::GetY() {
	return m_y;
}

void Vector2::Set(float _x, float _y) {
	m_x = _x;
	m_y = _y;
}

Vector2 Entity::Get() {
	return position;
}

void Entity::Set(Vector2 V) {
	position = V;
}

void AMovable::SetDir(Vector2 Dir) {
	m_direction = Dir;
}

void AMovable::SetVit(float Vit) {
	m_vitesse = Vit;
}

float Alive::GetAct() {
	return m_actvie;
}

float Alive::GetMax(){
	return m_maxvie;
}

void Alive::TakeDamage(float valeur) {
	m_actvie -= valeur;
}

void BreakableObject::TakeDamage(float valeur) {
	Alive::TakeDamage(valeur);
	if (GetAct() <= 0) {
		std::cout << "Breakable Object just broke" << std::endl;
	}
}

void Mob::TakeDamage(float valeur) {
	Alive::TakeDamage(valeur);
	if (GetAct() <= 0) {
		std::cout << "Mob just die" << std::endl;
	}
};

void Mob::Deplacement(Vector2 Direction, float Vitesse) {
	
	std::cout << "Mob move to x = " << x << " and y = " << y << std::endl;
}

void Player::TakeDamage(float valeur) {
	std::cout << "Player just die" << std::endl;
};

void Player::Deplacement(float x, float y) {
	std::cout << "Player moved to x = " << x << " and y = " << y << std::endl;
}

int main() {
	Vector2 A;
	float a;
	A.Set(6.9,7.48);
	StaticObject
	/*Entity vector(Vector2 A);
		Point p;
		p.ToString();
		std::vector < int >* sArray = new std::vector < int >();
		int a;
		int incr = 0;

		while (true) {
			int i = 0;
			std::cout << "Tapez le nombre a entrer : ";
			std::cin >> a;
			sArray->push_back(a);

			while (i < incr + 1) {
				std::cout << (*sArray)[i];
				i = i + 1;
			}
			incr = incr + 1;
			std::cout << "\n";
		}*/;
	
	return 0;
}