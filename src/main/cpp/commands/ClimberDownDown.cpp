#include "commands/ClimberDownDown.h"

ClimberDownDown::ClimberDownDown(ClimberSubsystem* subsystem, frc::XboxController* controller) 
    : m_climber(subsystem), m_controller(controller)  {
  AddRequirements({subsystem});
}

void ClimberDownDown::Initialize() {

}

void ClimberDownDown::Execute() {
  m_climber->DownDown();
}

void ClimberDownDown::End(bool interrupted) {
  m_climber->Stop();
}

bool ClimberDownDown::IsFinished() {
  return false;
}