#pragma once

#include <ctre/Phoenix.h>
#include <frc/VictorSP.h>

#include <frc2/command/SubsystemBase.h>

class ClimberSubsystem : public frc2::SubsystemBase {
 public: 
  ClimberSubsystem();

  void Periodic() override;

  void ClimberUp();

  void ClimberDown();

  void RunWinch();

  void ClimberStop();

 private:

  WPI_VictorSPX Climber{7};   //Climber lift
  WPI_VictorSPX Winch{11};    //Climber

};