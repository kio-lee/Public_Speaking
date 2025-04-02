// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LoggerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PUBLIC_SPEAKING_API ALoggerGameMode : public AGameModeBase
{
	GENERATED_BODY()
	TArray<FString> Messages;
	FString FileName = "log";
	virtual void PreExit();
	virtual void GameEnding();

public:
	UFUNCTION(BlueprintCallable, Category = "Logger") 
	void AddMessage(const FString& Message);

	UFUNCTION(BlueprintCallable)
	void SaveFileToFile() const; 
	
};
