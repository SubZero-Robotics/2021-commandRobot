/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnToLimeLight.h"

#include <frc/controller/PIDController.h>

#include <cmath>

// code based on this example
// https://github.com/wpilibsuite/allwpilib/tree/master/wpilibcExamples/src/main/cpp/examples/GyroDriveCommands
// The example uses the lambda in the constructor to do everything.  Ick.
// left the regular TurnToAngle that way, and trying to re-write this in a more clear way

TurnToLimelight::TurnToLimelight(DriveSubsystem* subsystem) : m_drive(subsystem) { 
        AddRequirements({subsystem});
}

void TurnToLimelight::Initialize() {
  // put limelight in vision mode
  m_drive->SelectLimelightPipeline(0);
  // Initialize PID controller
  m_controller.SetPID(kTurnP, kTurnI, kTurnD);
  // Set the controller to be continuous (because it is an angle controller)
  m_controller.EnableContinuousInput(-180, 180);
  // Set the controller tolerance - the delta tolerance ensures the robot is
  // stationary at the setpoint before it is considered as having reached the
  // reference
  m_controller.SetTolerance(kTurnTolerance.to<double>(),
                            kTurnRateTolerance.to<double>());
  // Set reference to target.  Make sure it fits in -180,180
  m_controller.SetSetpoint(m_drive->SanitizeAngle(m_drive->GetLimelightTargetAngle()).to<double>());
}

void TurnToLimelight::Execute() {
  // Each tick, adjust setpoint just in case
  m_controller.SetSetpoint(m_drive->SanitizeAngle(m_drive->GetLimelightTargetAngle()).to<double>());
  // And turn to the output
  m_drive->ArcadeDrive(0, m_controller.Calculate(m_drive->GetHeading().to<double>()));
}

void TurnToLimelight::End(bool interrupted) {
  // return limelight to camera mode
  m_drive->SelectLimelightPipeline(1);
  // stop drive
  m_drive->ArcadeDrive(0.0, 0.0);
  // reset controller, in case it gets re-used
  m_controller.Reset();
}

bool TurnToLimelight::IsFinished() { return m_controller.AtSetpoint(); }
