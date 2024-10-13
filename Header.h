#pragma once

#ifndef FUNC_H__
#define FUNC_H__
/*class Point {

public:
	float x;
	float y;
	float z;

	std::string ToString();
};*/

class Vector2 {
	float m_x;
	float m_y;
public:
	float GetX();
	float GetY();
	void Set(float _x, float _y);
};

class Entity {
	//Variables
	Vector2 position;

public:
	Entity(Vector2 V) {
		position = V;
	}

	virtual Vector2 Get();

	virtual void Set(Vector2 V);

	void afficher() {
		std::cout << position.GetX() << " " << position.GetY() << std::endl;
	}
};

class AMovable {
	Vector2 m_direction;
	float m_vitesse;

public:
	AMovable(Vector2 D, float V) {
		m_direction = D;
		m_vitesse = V;
	}

	virtual void SetDir(Vector2 direction);
	virtual void SetVit(float vitesse);
	virtual void Deplacement(Vector2 Direction, float Vitesse) = 0;
};

class Alive {
	float m_maxvie;
	float m_actvie;

public:
	Alive(float maxvie, float actvie) {
		m_maxvie = maxvie;
		m_actvie = actvie;
	}

	virtual float GetMax();
	virtual float GetAct();
	virtual void TakeDamage(float valeur);
};

class IAttacker {
public :
	virtual void Attack(class Alive* Vie) = 0;
};

class StaticObject : Entity {
public:
	StaticObject(Vector2 V) : Entity(V) {
		std::cout << "Static Object just created at x = " << V.GetX() << " and y = " << V.GetY() << std::endl;
	};
};

class BreakableObject : Entity, Alive {
public:
	BreakableObject(Vector2 V, float maxvie, float actvie) : Entity(V), Alive(maxvie, actvie) {
		std::cout << "Breakable Object just created at x = " << V.GetX() << " and y = " << V.GetY() << " with " << maxvie << " life" << std::endl;
	};

	void TakeDamage(float valeur) override;
};

class Mob : Entity, Alive, AMovable {
public:
	Mob(Vector2 V, float maxvie, float actvie, Vector2 D) : Entity(V), Alive(maxvie, actvie), AMovable(D, 0) {
		std::cout << "Mob just created at x = " << V.GetX() << " and y = " << V.GetY() << " with " << maxvie << " life with direction x = " << D.GetX() << "and y = " << D.GetY() << std::endl;
	};

	void TakeDamage(float valeur) override;

	void Deplacement(Vector2 Deplacement, float Vitesse) override;
};

class Player : Entity, Alive, AMovable, IAttacker {
	Player(Vector2 V, float maxvie, float actvie, Vector2 D) : Entity(V), Alive(maxvie, actvie), AMovable(D, 0) {
		std::cout << "Player just created at x = " << V.GetX() << " and y = " << V.GetY() << " with " << maxvie << " life with direction x = " << D.GetX() << "and y = " << D.GetY() << std::endl;
	};

	void TakeDamage(float valeur) override;

	void Deplacement(float x, float y) override;

	void Attack(Alive& Vie) override;

};
/*class Integer {
	//Variables
	int m_nbr;

public:
	//Constructeurs
	Integer(){
		m_nbr = 0;
	}

	Integer(int x) {
		m_nbr = x;
	}
	
	//Opérateurs logiques
	Integer operator+(const Integer& i) {
		return Integer(m_nbr + i.m_nbr);
	}

	Integer operator-(const Integer& i) {
		return Integer(m_nbr - i.m_nbr);
	}

	Integer operator*(const Integer& i) {
		return Integer(m_nbr * i.m_nbr);
	}

	Integer operator/(const Integer& i) {
		return Integer(m_nbr / i.m_nbr);
	}

	Integer operator%(const Integer& i) {
		return Integer(m_nbr % i.m_nbr);
	}

	Integer operator<<(const Integer& i) {
		return Integer(m_nbr << i.m_nbr);
	}

	//Opérateurs logiques avec égals
	Integer operator+=(const Integer& i) {
		return Integer(m_nbr = m_nbr+i.m_nbr);
	}

	Integer operator-=(const Integer& i) {
		return Integer(m_nbr = m_nbr - i.m_nbr);
	}

	Integer operator*=(const Integer& i) {
		return Integer(m_nbr = m_nbr * i.m_nbr);
	}

	Integer operator/=(const Integer& i) {
		return Integer(m_nbr = m_nbr / i.m_nbr);
	}

	Integer operator%=(const Integer& i) {
		return Integer(m_nbr = m_nbr % i.m_nbr);
	}

	//Fonctions
	Integer pow(int exp) {
		int x = 0;
		Integer res(1);
		while (x < exp) {
			res *= m_nbr;
			x += 1;
		}
		return Integer(res);
	}

	void afficher() const {
		std::cout << m_nbr << std::endl;
	}
};*/
#endif