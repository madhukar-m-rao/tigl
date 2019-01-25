/*
* Copyright (C) 2019 German Aerospace Center (DLR/SC)
*
* Created: 2019-01-25 Martin Siggel <martin.siggel@dlr.de>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "TIGLViewerUndoCommands.h"

#include <cassert>
#include <Quantity_Color.hxx>

namespace TiGLViewer
{

void DeleteObjects::redo()
{
    for (Handle(AIS_InteractiveObject) obj : myObjects) {
        myContext->Clear(obj, Standard_False);
    }
    myContext->UpdateCurrentViewer();
}

void DeleteObjects::undo()
{
    for (Handle(AIS_InteractiveObject) obj : myObjects) {
        myContext->Display(obj, Standard_False);
    }
    myContext->UpdateCurrentViewer();
}

ChangeObjectsColor::ChangeObjectsColor(Handle(AIS_InteractiveContext) context,
                                       std::vector<Handle(AIS_InteractiveObject)> objects, QColor col)
    : myContext(context)
    , myObjects(objects)
    , myColor(col)
{
    setText("Change color");

    // store old colors
    for (auto obj : myObjects) {
        Quantity_Color oldCol;
        obj->Color(oldCol);
        myOldCols.push_back(oldCol);
    }
}

void ChangeObjectsColor::redo()
{
    for (auto obj : myObjects) {
        myContext->SetColor(
            obj,
            Quantity_Color(myColor.red() / 255.,
                           myColor.green() / 255.,
                           myColor.blue() / 255.,
                           Quantity_TOC_RGB),
            Standard_False);
    }
    myContext->UpdateCurrentViewer();
}

void ChangeObjectsColor::undo()
{
    assert(myObjects.size() == myOldCols.size());
    for (size_t iobj = 0; iobj < myObjects.size(); iobj++) {
        Handle(AIS_InteractiveObject) obj = myObjects[iobj];
        Quantity_Color& col               = myOldCols[iobj];
        myContext->SetColor(obj, col, Standard_False);
    }
    myContext->UpdateCurrentViewer();
}

DrawObjects::DrawObjects(Handle(AIS_InteractiveContext) context, Handle(AIS_InteractiveObject) object,
                         const std::string& objectName, bool updateViewer)
    : myContext(context)
    , myUpdate(updateViewer)
{
    setText(QString("Draw %1").arg(objectName.c_str()));
    myObjects.push_back(object);
}

DrawObjects::DrawObjects(Handle(AIS_InteractiveContext) context, std::vector<Handle(AIS_InteractiveObject)> objects,
                         const std::string& objectName, bool updateViewer)
    : myContext(context)
    , myUpdate(updateViewer)
{
    setText(QString("Draw %1").arg(objectName.c_str()));
    for (auto object : objects) {
        myObjects.push_back(object);
    }
}

void DrawObjects::redo()
{
    for (Handle(AIS_InteractiveObject) obj : myObjects) {
        myContext->Display(obj, Standard_False);
    }
    if (myUpdate) {
        myContext->UpdateCurrentViewer();
    }
}

void DrawObjects::undo()
{
    myUpdate = true;
    for (auto obj : myObjects) {
        myContext->Erase(obj, Standard_False);
    }
    myContext->UpdateCurrentViewer();
}

bool DrawObjects::mergeWith(const QUndoCommand* other)
{
    if (other->id() != id()) {
        return false;
    }

    setText("Draw Objects");

    for (auto obj : static_cast<const DrawObjects*>(other)->myObjects) {
        myObjects.push_back(obj);
    }
    return true;
}

} // namespace TiGLViewer
