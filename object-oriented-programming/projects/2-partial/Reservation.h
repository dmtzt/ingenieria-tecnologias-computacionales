/*
 * Reservation.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 2/5/2019
 */

#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include "Date.h"

using namespace std;

class Reservation
{
	private:
		int materialID, clientID;
		Date reservationDate;
	public:
		Reservation();
		Reservation(int, int, Date);
		int getMaterialID();
		int getClientID();
		Date getReservationDate();
		void setMaterialID(int);
		void setClientID(int);
		void setReservationDate(Date);
		void toString();
		Date calculateEndReservation(int);
};

Reservation::Reservation()
{
	materialID = 0;
	clientID = 0;
}

Reservation::Reservation(int materialID, int clientID, Date reservationDate)
{
	this->materialID = materialID;
	this->clientID = clientID;
	this->reservationDate = reservationDate;
}

int Reservation::getMaterialID()
{
	return materialID;
}

int Reservation::getClientID()
{
	return clientID;
}

Date Reservation::getReservationDate()
{
	return reservationDate;
}

void Reservation::setMaterialID(int materialID)
{
	this->materialID = materialID;
}

void Reservation::setClientID(int clientID)
{
	this->clientID = clientID;
}

void Reservation::setReservationDate(Date reservationDate)
{
	this->reservationDate = reservationDate;
}

void Reservation::toString()
{
	cout << materialID << " " << clientID << " " << reservationDate;
}

Date Reservation::calculateEndReservation(int days)
{
	return reservationDate + days;
}

#endif