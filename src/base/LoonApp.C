#include "LoonApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<LoonApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

LoonApp::LoonApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  LoonApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  LoonApp::associateSyntax(_syntax, _action_factory);
}

LoonApp::~LoonApp()
{
}

void
LoonApp::registerApps()
{
  registerApp(LoonApp);
}

void
LoonApp::registerObjects(Factory & factory)
{
}

void
LoonApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
