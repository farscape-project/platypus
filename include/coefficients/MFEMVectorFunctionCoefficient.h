#pragma once
#include "MFEMVectorCoefficient.h"

class MFEMVectorFunctionCoefficient : public MFEMVectorCoefficient
{
public:
  static InputParameters validParams();

  MFEMVectorFunctionCoefficient(const InputParameters & parameters);
  virtual ~MFEMVectorFunctionCoefficient();

  std::shared_ptr<mfem::VectorCoefficient> getVectorCoefficient() const override
  {
    return _vector_coefficient;
  }

private:
  std::shared_ptr<mfem::VectorFunctionCoefficient> _vector_coefficient{nullptr};
};
