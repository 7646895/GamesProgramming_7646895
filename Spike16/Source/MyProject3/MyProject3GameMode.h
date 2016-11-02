// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MyProject3GameMode.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API AMyProject3GameMode : public AGameMode
{
	GENERATED_BODY()
	public:

	AMyProject3GameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Switch Variables")
    float yPosition;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Switch Variables")
    float xPosition;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Switch Variables")
    float zPosition;
	
	UFUNCTION(BlueprintCallable, Category="Switch Functions")
	float getYPos();

	UFUNCTION(BlueprintCallable, Category="Switch Functions")
	void setYPos(float y);
	
};
