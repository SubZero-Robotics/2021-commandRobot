/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/Phoenix.h>
#include <frc/VictorSP.h>
#include <frc/Encoder.h>
#include <frc/AnalogInput.h>
#include <AHRS.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <units/voltage.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTableEntry.h>

//#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  /**
   * Drives the robot using arcade controls.
   *
   * @param fwd the commanded forward movement
   * @param rot the commanded rotation
   */
  void ArcadeDrive(double fwd, double rot);

  /**
   * Controls each side of the drive directly with a voltage.
   *
   * @param left the commanded left output
   * @param right the commanded right output
   */
  void TankDriveVolts(units::volt_t left, units::volt_t right);

  /**
   * Resets the drive encoders to currently read a position of 0.
   */
  void ResetEncoders();

  /**
   * Gets the average distance of the TWO encoders.
   *
   * @return the average of the TWO encoder readings (left and right)
   */
  double GetAverageEncoderDistance();

  /**
   * Gets the left drive encoder.
   *
   * @return the left drive encoder
   */
  frc::Encoder& GetLeftEncoder();

  /**
   * Gets the right drive encoder.
   *
   * @return the right drive encoder
   */
  frc::Encoder& GetRightEncoder();

  /**
   * Sets the max output of the drive.  Useful for scaling the drive to drive
   * more slowly.
   *
   * @param maxOutput the maximum output to which the drive will be constrained
   */
  void SetMaxOutput(double maxOutput);

  /**
   * Returns the heading of the robot.
   *
   * @return the robot's heading in degrees, from 180 to 180
   */
  units::degree_t GetHeading();

  /**
   * Returns the turn rate of the robot.
   *
   * @return The turn rate of the robot, in degrees per second
   */
  double GetTurnRate();

  /**
   * Returns the heading to the limelight target
   *
   * @return The heading at which the limelight target sits
   */
  units::degree_t GetLimelightTargetAngle();

  /**
   * Returns the currently-estimated pose of the robot.
   *
   * @return The pose.
   */
  frc::Pose2d GetPose();

  /**
   * Returns the current wheel speeds of the robot.
   *
   * @return The current wheel speeds.
   */
  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

  /**
   * Resets the odometry to the specified pose.
   *
   * @param pose The pose to which to set the odometry.
   */
  void ResetOdometry(frc::Pose2d pose);

  /**
   *
   * Chooses the active limelight pipeline
   */
  void SelectLimelightPipeline(int pipeline);

  /**
   *
   * Sets Gyro angle to Zero
   */
  void ZeroGyro(void);

 /**
   * Returns the ultrasonic sensor's distance
   *
   * @return The range from the ultrasonic sensor, in inches
   */
  double GetDistance();

 /**
   * make sure target angle is in the right range
   *
   * @return The angle to turn to, put into -180,180 degrees
   */
  units::degree_t SanitizeAngle(units::degree_t target);

  private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // right motor controllers
  WPI_TalonFX RightLead{3};
  WPI_TalonFX RightFollow{4};
  // left motor controllers
  WPI_TalonFX LeftLead{1};
  WPI_TalonFX LeftFollow{2};

  frc::DifferentialDrive m_drive{RightLead, LeftLead};

  // encoders here, if we get them
  frc::Encoder m_leftEncoder;
  frc::Encoder m_rightEncoder;
  
  // The default (starting) values for the encoder
  double lEncoder = 0.0;
  double rEncoder = 0.0;

  // Ultrasonic Ranger
  frc::AnalogInput Ultrasonic{0};
  double Distance = 0.0;    // the ranger distance

  // navx
  double gyroAngle = 0.0;   // What is the angle (degrees) from the gyro?
  double gyroRate = 0.0;    // What is angle change (deg/sec)
  AHRS ahrs{frc::SPI::Port::kMXP};

  // limelight
  float tx = 0.0;           // limelight angle off left/right
  int tv = 0;               // does the limelight have a target?
  // pointer to network tables for limelight stuff
  std::shared_ptr<NetworkTable> table;
};
