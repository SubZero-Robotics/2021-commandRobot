#include "commands/RunWinchWinch.h"
#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ClimberSubsystem.h"

void RunWinchWinch::Initialize() {

}

void RunWinchWinch::Execute() {
  m_climber->RunWinch();
}

void RunWinchWinch::End(bool interrupted) {
 // m_climber->Stop();
}

bool RunWinchWinch::IsFinished() {
  return false;
}