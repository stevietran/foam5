/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2014-2016 OpenFOAM Foundation
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

Class
    Foam::atmThermalBoundaryLayerInletKFvPatchScalarField

Group
    grpRASBoundaryConditions grpInletBoundaryConditions

Description
    This boundary condition specifies an inlet value for the turbulence
    kinetic energy, \f$k\f$, appropriate for atmospheric boundary layers.

    See Foam::atmThermalBoundaryLayer for details.

    Example of the boundary condition specification:
    \verbatim
    ground
    {
        type            atmThermalBoundaryLayerInletK;
        z               (0 0 1);
        Uref            10.0;
        Zref            20.0;
        z0              uniform 0.1;
        zGround         uniform 0.0;
    }
    \endverbatim

See also
    Foam::atmThermalBoundaryLayer,
    Foam::atmThermalBoundaryLayerInletVelocityFvPatchVectorField,
    Foam::atmThermalBoundaryLayerInletEpsilonFvPatchScalarField

SourceFiles
    atmThermalBoundaryLayerInletKFvPatchScalarField.C

\*---------------------------------------------------------------------------*/

#ifndef atmThermalBoundaryLayerInletKFvPatchScalarField_H
#define atmThermalBoundaryLayerInletKFvPatchScalarField_H

#include "fvPatchFields.H"
#include "fixedValueFvPatchFields.H"
#include "atmThermalBoundaryLayer.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
        Class atmThermalBoundaryLayerInletKFvPatchScalarField Declaration
\*---------------------------------------------------------------------------*/

class atmThermalBoundaryLayerInletKFvPatchScalarField
:
    public fixedValueFvPatchScalarField,
    public atmThermalBoundaryLayer
{

public:

    //- Runtime type information
    TypeName("atmThermalBoundaryLayerInletK");


    // Constructors

        //- Construct from patch and internal field
        atmThermalBoundaryLayerInletKFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        atmThermalBoundaryLayerInletKFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given
        //  atmThermalBoundaryLayerInletKFvPatchScalarField onto a new patch
        atmThermalBoundaryLayerInletKFvPatchScalarField
        (
            const atmThermalBoundaryLayerInletKFvPatchScalarField&,
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchScalarField> clone() const
        {
            return tmp<fvPatchScalarField>
            (
                new atmThermalBoundaryLayerInletKFvPatchScalarField(*this)
            );
        }

        //- Construct as copy setting internal field reference
        atmThermalBoundaryLayerInletKFvPatchScalarField
        (
            const atmThermalBoundaryLayerInletKFvPatchScalarField&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchScalarField> clone
        (
            const DimensionedField<scalar, volMesh>& iF
        ) const
        {
            return tmp<fvPatchScalarField>
            (
                new atmThermalBoundaryLayerInletKFvPatchScalarField(*this, iF)
            );
        }


    // Member functions

        // Mapping functions

            //- Map (and resize as needed) from self given a mapping object
            virtual void autoMap
            (
                const fvPatchFieldMapper&
            );

            //- Reverse map the given fvPatchField onto this fvPatchField
            virtual void rmap
            (
                const fvPatchScalarField&,
                const labelList&
            );


        //- Write
        virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
