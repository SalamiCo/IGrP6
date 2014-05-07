//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once

#include "ObjetoCompuesto3D.h"
#include "Tablero.h"
#include "TColor.h"
#include "TCubo.h"
#include "TCilindro.h"
#include "BolasCompuesto.h"

class MesaBillar : public ObjetoCompuesto3D
{
public:
	MesaBillar(void);
	~MesaBillar(void){};
};