#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ClimberSubsystem.h"

#include "Constants.h" 

void ClimberSubsystem::Periodic() {

}

void ClimberSubsystem::ClimberUp(){
  Winch.Set(ControlMode::PercentOutput, 0.35);//.35, .65
}

void ClimberSubsystem::ClimberDown(){
  Winch.Set(ControlMode::PercentOutput, -0.35);//-.35, .65
}

void ClimberSubsystem::RunWinch(){
  Climber.Set(ControlMode::PercentOutput, -0.8);//.5, .8
}

void ClimberSubsystem::ClimberStop(){
  Climber.Set(ControlMode::PercentOutput, 0);
}