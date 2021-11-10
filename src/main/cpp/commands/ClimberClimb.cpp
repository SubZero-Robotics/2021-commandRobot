#include "commands/ClimberClimb.h"

ClimberClimb::ClimberClimb(ClimberSubsystem* subsystem, frc::XboxController* controller) 
    : m_climber(subsystem), m_controller(controller)  {
  AddRequirements({subsystem});
}

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