#include "commands/ClimberClimb.h"
#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ClimberSubsystem.h"

void ClimberClimb::Initialize() {

}

void ClimberClimb::Execute() {
  m_climber->Climb();
}

void ClimberClimb::End(bool interrupted) {
 // m_climber->Stop();
}

bool ClimberClimb::IsFinished() {
  return false;
}