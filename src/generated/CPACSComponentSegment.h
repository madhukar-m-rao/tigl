// Copyright (c) 2016 RISC Software GmbH
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

#include <tixi.h>
#include <string>
#include <boost/optional.hpp>
#include "tigl_internal.h"
#include <CCPACSWingCSStructure.h>
#include "CPACSControlSurfaces.h"
#include "CPACSComponentSegmentPath.h"
#include "CPACSWingFuselageAttachments.h"
#include "CPACSWingStructuralMounts.h"

namespace tigl
{
    class CCPACSWingComponentSegments;
    
    namespace generated
    {
        // This class is used in:
        // CPACSComponentSegments
        
        // generated from /xsd:schema/xsd:complexType[144]
        class CPACSComponentSegment
        {
        public:
            TIGL_EXPORT CPACSComponentSegment(CCPACSWingComponentSegments* parent);
            
            TIGL_EXPORT virtual ~CPACSComponentSegment();
            
            TIGL_EXPORT CCPACSWingComponentSegments* GetParent() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const std::string& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            
            TIGL_EXPORT bool HasDescription() const;
            TIGL_EXPORT const std::string& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            
            TIGL_EXPORT const std::string& GetFromElementUID() const;
            TIGL_EXPORT void SetFromElementUID(const std::string& value);
            
            TIGL_EXPORT const std::string& GetToElementUID() const;
            TIGL_EXPORT void SetToElementUID(const std::string& value);
            
            TIGL_EXPORT bool HasStructure() const;
            TIGL_EXPORT const CCPACSWingCSStructure& GetStructure() const;
            TIGL_EXPORT CCPACSWingCSStructure& GetStructure();
            
            TIGL_EXPORT bool HasControlSurfaces() const;
            TIGL_EXPORT const CPACSControlSurfaces& GetControlSurfaces() const;
            TIGL_EXPORT CPACSControlSurfaces& GetControlSurfaces();
            
            TIGL_EXPORT bool HasPath() const;
            TIGL_EXPORT const CPACSComponentSegmentPath& GetPath() const;
            TIGL_EXPORT CPACSComponentSegmentPath& GetPath();
            
            TIGL_EXPORT bool HasWingFuselageAttachments() const;
            TIGL_EXPORT const CPACSWingFuselageAttachments& GetWingFuselageAttachments() const;
            TIGL_EXPORT CPACSWingFuselageAttachments& GetWingFuselageAttachments();
            
            TIGL_EXPORT bool HasWingStructuralMounts() const;
            TIGL_EXPORT const CPACSWingStructuralMounts& GetWingStructuralMounts() const;
            TIGL_EXPORT CPACSWingStructuralMounts& GetWingStructuralMounts();
            
        protected:
            CCPACSWingComponentSegments* m_parent;
            
            std::string                                   m_uID;
            std::string                                   m_name;
            boost::optional<std::string>                  m_description;
            std::string                                   m_fromElementUID;
            std::string                                   m_toElementUID;
            boost::optional<CCPACSWingCSStructure>        m_structure;
            boost::optional<CPACSControlSurfaces>         m_controlSurfaces;
            boost::optional<CPACSComponentSegmentPath>    m_path;
            boost::optional<CPACSWingFuselageAttachments> m_wingFuselageAttachments;
            boost::optional<CPACSWingStructuralMounts>    m_wingStructuralMounts;
            
        private:
            #ifdef HAVE_CPP11
            CPACSComponentSegment(const CPACSComponentSegment&) = delete;
            CPACSComponentSegment& operator=(const CPACSComponentSegment&) = delete;
            
            CPACSComponentSegment(CPACSComponentSegment&&) = delete;
            CPACSComponentSegment& operator=(CPACSComponentSegment&&) = delete;
            #else
            CPACSComponentSegment(const CPACSComponentSegment&);
            CPACSComponentSegment& operator=(const CPACSComponentSegment&);
            #endif
        };
    }
    
    // This type is customized, use type CCPACSWingComponentSegment
}
