#pragma once
#include "MFEMEssentialBC.h"

class MFEMVectorDirichletBC : public MFEMEssentialBC
{
protected:
  std::vector<Real> _vec_value;
  std::shared_ptr<mfem::VectorConstantCoefficient> _vec_coef{nullptr};
  enum APPLY_TYPE
  {
    STANDARD,
    TANGENTIAL,
    NORMAL
  };

public:
  static InputParameters validParams();

  MFEMVectorDirichletBC(const InputParameters & parameters);

  void ApplyBC(mfem::GridFunction & gridfunc, mfem::Mesh * mesh_) override;

  APPLY_TYPE _boundary_apply_type;
};
