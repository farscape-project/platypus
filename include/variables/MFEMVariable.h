#pragma once

#include "MFEMFESpace.h"
#include "GeneralUserObject.h"

class MFEMVariable : public GeneralUserObject
{
public:
  static InputParameters validParams();

  MFEMVariable(const InputParameters & parameters);
  virtual ~MFEMVariable();
  virtual void execute() override {}
  virtual void initialize() override {}
  virtual void finalize() override {}

  const MFEMFESpace & fespace;
  unsigned int components;
};
