// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "MyProject3GameMode.h"

AMyProject3GameMode::AMyProject3GameMode()
{
}

float AMyProject3GameMode::getYPos()
{
	return yPosition;
}

void AMyProject3GameMode::setYPos(float y)
{
	yPosition = y;
}
