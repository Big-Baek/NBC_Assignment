// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"

class USpringArmComponent; // 스프링 암 관련 클래스 헤더
class UCameraComponent; // 카메라 관련 클래스 전방 선언
class UWidgetComponent;
struct FInputActionValue;


UCLASS()
class PJ_LEARNING_API ASpartaCharacter : public ACharacter
{
    GENERATED_BODY()

    //스크린모드
    //월드

public:
    ASpartaCharacter();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    USpringArmComponent* SpringArmComp;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* CameraComp;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
    UWidgetComponent* OverheadWidget;



    // 현재 체력을 가져오는 함수
    UFUNCTION(BlueprintPure, Category = "Health")
    float GetHealth() const;
    // 체력을 회복시키는 함수
    UFUNCTION(BlueprintCallable, Category = "Health")
    void AddHealth(float Amount);

protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION()
    void Move(const FInputActionValue& value);
    UFUNCTION()
    void StartJump(const FInputActionValue& value);
    UFUNCTION()
    void StopJump(const FInputActionValue& value);
    UFUNCTION()
    void Look(const FInputActionValue& value);
    UFUNCTION()
    void StartSprint(const FInputActionValue& value);
    UFUNCTION()
    void StopSprint(const FInputActionValue& value);

    // 최대 체력
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float MaxHealth;
    // 현재 체력
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
    float Health;
    // 사망 처리 함수 (체력이 0 이하가 되었을 때 호출)
    UFUNCTION(BlueprintCallable, Category = "Health")
    virtual void OnDeath();
    void UpdateOverheadHP();
    // 데미지 처리 함수 - 외부로부터 데미지를 받을 때 호출됨
// 또는 AActor의 TakeDamage()를 오버라이드
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

    virtual void BeginPlay() override;
private:
    float NormalSpeed;
    float SprintSpeedMultiplier;
    float SprintSpeed;
};
