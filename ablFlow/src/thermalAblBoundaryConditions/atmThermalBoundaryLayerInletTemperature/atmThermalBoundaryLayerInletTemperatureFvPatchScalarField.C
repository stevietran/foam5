/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "atmThermalBoundaryLayerInletTemperatureFvPatchScalarField.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

atmThermalBoundaryLayerInletTemperatureFvPatchScalarField::
atmThermalBoundaryLayerInletTemperatureFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchScalarField(p, iF),
    atmThermalBoundaryLayer()
{}


atmThermalBoundaryLayerInletTemperatureFvPatchScalarField::
atmThermalBoundaryLayerInletTemperatureFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchScalarField(p, iF, dict, false),
    atmThermalBoundaryLayer(patch().Cf(), dict)
{
    scalarField::operator=(T(patch().Cf()));
}


atmThermalBoundaryLayerInletTemperatureFvPatchScalarField::
atmThermalBoundaryLayerInletTemperatureFvPatchScalarField
(
    const atmThermalBoundaryLayerInletTemperatureFvPatchScalarField& pvf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchScalarField(pvf, p, iF, mapper),
    atmThermalBoundaryLayer(pvf, mapper)
{}


atmThermalBoundaryLayerInletTemperatureFvPatchScalarField::
atmThermalBoundaryLayerInletTemperatureFvPatchScalarField
(
    const atmThermalBoundaryLayerInletTemperatureFvPatchScalarField& pvf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchScalarField(pvf, iF),
    atmThermalBoundaryLayer(pvf)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void atmThermalBoundaryLayerInletTemperatureFvPatchScalarField::autoMap
(
    const fvPatchFieldMapper& m
)
{
    fixedValueFvPatchScalarField::autoMap(m);
    atmThermalBoundaryLayer::autoMap(m);
}


void atmThermalBoundaryLayerInletTemperatureFvPatchScalarField::rmap
(
    const fvPatchScalarField& pvf,
    const labelList& addr
)
{
    fixedValueFvPatchScalarField::rmap(pvf, addr);

    const atmThermalBoundaryLayerInletTemperatureFvPatchScalarField& blpvf =
        refCast<const atmThermalBoundaryLayerInletTemperatureFvPatchScalarField>(pvf);

    atmThermalBoundaryLayer::rmap(blpvf, addr);
}


void atmThermalBoundaryLayerInletTemperatureFvPatchScalarField::write(Ostream& os) const
{
    fvPatchScalarField::write(os);
    atmThermalBoundaryLayer::write(os);
    writeEntry("value", os);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makePatchTypeField
(
    fvPatchScalarField,
    atmThermalBoundaryLayerInletTemperatureFvPatchScalarField
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
