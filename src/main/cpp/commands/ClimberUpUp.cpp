#include "commands/ClimberUpUp.h"
#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ClimberSubsystem.h"

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