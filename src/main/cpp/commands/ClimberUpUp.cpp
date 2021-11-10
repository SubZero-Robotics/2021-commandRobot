#include "commands/ClimberUpUp.h"

ClimberUpUp::ClimberUpUp(ClimberSubsystem* subsystem, frc::XboxController* controller) 
    : m_climber(subsystem), m_controller(controller)  {
  AddRequirements({subsystem});
}

void ClimberUpUp::Initialize() {

}

void ClimberUpUp::Execute() {
  m_climber->UpUp();
}

void ClimberUpUp::End(bool interrupted) {
 // m_climber->Stop();
}

bool ClimberUpUp::IsFinished() {
  return false;
}