// Fill out your copyright notice in the Description page of Project Settings.


#include "LoggerGameMode.h"
#include "Misc/DateTime.h"
void ALoggerGameMode::AddMessage(const FString& Message)
{
	const auto Time = FDateTime().Now(); 
	const FString FormatedString = FString::Printf(TEXT("(%s : %s)"),*Time.ToString() , *Message);
	Messages.Add(FormatedString);
}

void ALoggerGameMode::SaveFileToFile() const
{
	const auto Time = FDateTime().Now(); 
	FString File = FPaths::ProjectConfigDir();
	File.Append(FString::Printf(TEXT("log%s.log"),*Time.ToString()) );

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	
	// Always first check if the file that you want to manipulate exist.
	if (!FileManager.FileExists(*File))
	{
		// We use the LoadFileToString to load the file into
		if(FFileHelper::SaveStringArrayToFile(Messages,*File))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Successfully Written: \"%d\" FStrings to the text file"),Messages.Num());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Failed to write FString to file."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read file because it was not found."));
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"),*File);
	}
	
	

	
}
