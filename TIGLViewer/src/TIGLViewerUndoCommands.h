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

#ifndef TIGLVIEWERUNDOCOMMANDS_H
#define TIGLVIEWERUNDOCOMMANDS_H

#include "tigl_internal.h"

#include <QUndoCommand>
#include <QColor>
#include <vector>

#include <AIS_InteractiveObject.hxx>
#include <AIS_InteractiveContext.hxx>

namespace TiGLViewer
{

class DeleteObjects : public QUndoCommand
{
public:
    DeleteObjects(Handle(AIS_InteractiveContext) context, std::vector<Handle(AIS_InteractiveObject)> objects)
        : myContext(context)
        , myObjects(objects)
    {
        setText("Delete objects");
    }

    // QUndoCommand interface
public:
    void redo() OVERRIDE;
    void undo() OVERRIDE;
    int id() const OVERRIDE
    {
        return 1000;
    }

private:
    Handle(AIS_InteractiveContext) myContext;
    std::vector<Handle(AIS_InteractiveObject)> myObjects;
};

class ChangeObjectsColor : public QUndoCommand
{
public:
    ChangeObjectsColor(Handle(AIS_InteractiveContext) context,
                       std::vector<Handle(AIS_InteractiveObject)> objects,
                       QColor col);

    // QUndoCommand interface
public:
    void redo() OVERRIDE;
    void undo() OVERRIDE;
    int id() const OVERRIDE
    {
        return 1001;
    }

private:
    Handle(AIS_InteractiveContext) myContext;
    std::vector<Handle(AIS_InteractiveObject)> myObjects;
    QColor myColor;
    std::vector<Quantity_Color> myOldCols;
};

class DrawObjects : public QUndoCommand
{
public:
    DrawObjects(Handle(AIS_InteractiveContext) context, Handle(AIS_InteractiveObject) object,
                const std::string& objectName, bool updateViewer);

    DrawObjects(Handle(AIS_InteractiveContext) context, std::vector<Handle(AIS_InteractiveObject)> objects,
                const std::string& objectName, bool updateViewer);

    void redo() OVERRIDE;
    void undo() OVERRIDE;
    bool mergeWith(const QUndoCommand* other) OVERRIDE;

    int id() const OVERRIDE
    {
        return 1002;
    }

private:
    Handle(AIS_InteractiveContext) myContext;
    std::vector<Handle(AIS_InteractiveObject)> myObjects;
    bool myUpdate;
};

} // namespace TiGLViewer

#endif // TIGLVIEWERUNDOCOMMANDS_H
