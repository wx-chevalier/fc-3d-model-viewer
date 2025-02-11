/****************************************************************************
* VCGLib                                                            o o     *
* Visual and Computer Graphics Library                            o     o   *
*                                                                _   O  _   *
* Copyright(C) 2004-2017                                           \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#ifndef VCG__FOREACH_H
#define VCG__FOREACH_H

#ifndef __VCG_MESH
#error "This file should not be included alone. It is automatically included by complex.h"
#endif

namespace vcg {
namespace tri {
/** \addtogroup trimesh
@{
*/

template <class MeshType>
inline void ForEachFacePos(MeshType &m, std::function<void (typename face::Pos<typename MeshType::FaceType>  &)> action)
{
  typedef typename face::Pos<typename MeshType::FaceType> PosType;
  
    for(auto fi=m.face.begin();fi!=m.face.end();++fi)
        if(!(*fi).IsD())
        {
            for(int i=0;i<3;++i)
            {
                PosType pi(&*fi,i);
                action(pi);
            }
        }
}

/**
 * ForEachFace Helper
 * to traverse all the faces of a mesh you can simply write something like:
 * 
 *      ForEachFace(m, [&](const FaceType &f){
 *         MakeSomethingWithFace(f);
 *      });
 *  
 */

template <class MeshType>
inline void ForEachFace(const MeshType &m, std::function<void (const typename MeshType::FaceType &)> action)
{
  if(m.fn == (int) m.face.size())
  {
    for(auto fi=m.face.begin();fi!=m.face.end();++fi) {
      action(*fi);
    }       
  }
  else
  {
    for(auto fi=m.face.begin();fi!=m.face.end();++fi)
      if(!(*fi).IsD())
      {
        action(*fi);
      }    
  }
}

template <class MeshType>
inline void ForEachFace(MeshType &m, std::function<void (typename MeshType::FaceType &)> action)
{
  if(m.fn == (int) m.face.size())
  {
    for(auto fi=m.face.begin();fi!=m.face.end();++fi) {
      action(*fi);
    }       
  }
  else
  {
    for(auto fi=m.face.begin();fi!=m.face.end();++fi)
      if(!(*fi).IsD())
      {
        action(*fi);
      }    
  }
}

/**
 * ForEachVertex Helper
 * to traverse all the vertexes of a mesh you can simply write something like:
 * 
 *      ForEachVertex(m, [&](const VertexType &v){
 *         MakeSomethingWithVertex(v);
 *      });
 *  
 */

template <class MeshType>
inline void ForEachVertex(MeshType &m, std::function<void (typename MeshType::VertexType &)> action)
{
  if(m.vn == (int) m.vert.size())
  {
    for(auto vi=m.vert.begin();vi!=m.vert.end();++vi) {
      action(*vi);
    }       
  }
  else
  {
    for(auto vi=m.vert.begin();vi!=m.vert.end();++vi)
      if(!(*vi).IsD())
      {
        action(*vi);
      }    
  }
}

/**
 * ForEachEdge Helper
 * to traverse all the vertexes of a mesh you can simply write something like:
 * 
 *      ForEachEdge(m, [&](const EdgeType &e){
 *         MakeSomethingWithEdge(e);
 *      });
 *  
 */

template <class MeshType>
inline void ForEachEdge(MeshType &m, std::function<void (typename MeshType::EdgeType &)> action)
{
  if(m.en == (int) m.edge.size())
  {
    for(auto ei=m.edge.begin();ei!=m.edge.end();++ei) {
      action(*ei);
    }       
  }
  else
  {
    for(auto ei=m.edge.begin();ei!=m.edge.end();++ei)
      if(!(*ei).IsD())
      {
        action(*ei);
      }    
  }
}



/** @} */ // end doxygen group trimesh
} // end namespace tri
} // end namespace vcg

#endif // VCG__FOREACH_H
