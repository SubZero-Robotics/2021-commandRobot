#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ClimberSubsystem.h"

#include "Constants.h" 

ClimberSubsystem::ClimberSubsystem() {

}

void ClimberSubsystem::Periodic() {

}

void ClimberSubsystem::UpUp(){
  Winch.Set(ControlMode::PercentOutput, 0.35);//.35, .65
}

void ClimberSubsystem::DownDown(){
  Winch.Set(ControlMode::PercentOutput, -0.35);//-.35, .65
}

void ClimberSubsystem::Climb(){
  Climber.Set(ControlMode::PercentOutput, -0.8);//.5, .8
}

void ClimberSubsystem::Stop(){
  Climber.Set(ControlMode::PercentOutput, 0);
}