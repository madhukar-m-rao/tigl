// Copyright (c) 2018 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <CCPACSEtaIsoLine.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSControlSurfaceContours

    // generated from /xsd:schema/xsd:complexType[167]
    class CPACSControlSurfaceAirfoil
    {
    public:
        TIGL_EXPORT CPACSControlSurfaceAirfoil();
        TIGL_EXPORT virtual ~CPACSControlSurfaceAirfoil();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSEtaIsoLine& GetEta() const;
        TIGL_EXPORT virtual CCPACSEtaIsoLine& GetEta();

        TIGL_EXPORT virtual const std::string& GetAirfoilUID() const;
        TIGL_EXPORT virtual void SetAirfoilUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetRotX() const;
        TIGL_EXPORT virtual void SetRotX(const double& value);

        TIGL_EXPORT virtual const double& GetRotZ() const;
        TIGL_EXPORT virtual void SetRotZ(const double& value);

        TIGL_EXPORT virtual const double& GetScalY() const;
        TIGL_EXPORT virtual void SetScalY(const double& value);

        TIGL_EXPORT virtual const double& GetScalZ() const;
        TIGL_EXPORT virtual void SetScalZ(const double& value);

    protected:
        CCPACSEtaIsoLine m_eta;
        std::string      m_airfoilUID;
        double           m_rotX;
        double           m_rotZ;
        double           m_scalY;
        double           m_scalZ;

    private:
#ifdef HAVE_CPP11
        CPACSControlSurfaceAirfoil(const CPACSControlSurfaceAirfoil&) = delete;
        CPACSControlSurfaceAirfoil& operator=(const CPACSControlSurfaceAirfoil&) = delete;

        CPACSControlSurfaceAirfoil(CPACSControlSurfaceAirfoil&&) = delete;
        CPACSControlSurfaceAirfoil& operator=(CPACSControlSurfaceAirfoil&&) = delete;
#else
        CPACSControlSurfaceAirfoil(const CPACSControlSurfaceAirfoil&);
        CPACSControlSurfaceAirfoil& operator=(const CPACSControlSurfaceAirfoil&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSControlSurfaceAirfoil = generated::CPACSControlSurfaceAirfoil;
#else
typedef generated::CPACSControlSurfaceAirfoil CCPACSControlSurfaceAirfoil;
#endif
} // namespace tigl
