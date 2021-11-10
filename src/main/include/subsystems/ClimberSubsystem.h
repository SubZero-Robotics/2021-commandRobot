/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/Phoenix.h>
#include <frc/VictorSP.h>

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class ClimberSubsystem : public frc2::SubsystemBase {
 public: 
  ClimberSubsystem();

  // Subsystem methods go here.

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void UpUp();

  void DownDown();

  void Climb();

  void Stop();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_VictorSPX Climber{7};   //Climber lift
  WPI_VictorSPX Winch{11};    //Climber

};