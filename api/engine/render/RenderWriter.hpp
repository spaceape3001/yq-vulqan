////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/trait/always_false.hpp>
#include <engine/render/IndexBufferObjectInfo.hpp>
#include <engine/render/Render3D.hpp>
#include <engine/render/Rendered.hpp>
#include <engine/render/Pipeline.hpp>
#include <engine/render/PipelineBuilder.hpp>
#include <engine/render/PipelineConfig.hpp>
#include <engine/render/PipelineUtils.hpp>
#include <engine/render/UniformBufferObjectInfo.hpp>
#include <engine/render/VertexBufferObjectInfo.hpp>
#include <basic/Mutable.hpp>
#include <math/glm_types.hpp>
#include <variant>

namespace yq {
    namespace engine {
    
        class Pipeline::Writer : public Meta::Writer, public PipelineBuilder {
        public:
        
            Writer(Pipeline*);
            Writer(Pipeline&);
            ~Writer();
            
        private:
            Pipeline*       m_pipeline  = nullptr;
        };

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
        template <typename C>
        class TypedPipeline : public Pipeline {
        public:
            class Builder;
            
            TypedPipeline(std::string_view name, RenderedInfo* parent, const std::source_location&sl) : Pipeline(name, parent, sl)
            {
            }
        };
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template <typename BO, typename C, typename T, typename A>
        struct MBA_StdVector : public BO {
            typedef std::vector<T,A> (C::*FN);
            FN m_fn;
            
            MBA_StdVector(FN fn, std::string_view name, Pipeline* parent, const std::source_location& sl) : 
                BO(name, parent, sl), m_fn(fn)
            {
            }
            
            BufferData get(const Rendered* r) const
            {
                if(!r)
                    return {};
                const std::vector<T,A>& data = (static_cast<const C*>(r)->*m_fn);
                return BufferData{ data.data(), data.size()*sizeof(T) };
            }
        };
        
        template <typename BO, typename C, typename T, typename A>
        struct MBA_MutableStdVector : public BO {
            typedef Mutable<std::vector<T,A>> (C::*FN);
            FN m_fn;
            
            MBA_MutableStdVector(FN fn, std::string_view name, Pipeline* parent, const std::source_location& sl) : 
                BO(name, parent, sl), m_fn(fn)
            {
            }
            
            BufferData get(const Rendered* r) const
            {
                if(!r)
                    return {};
                const Mutable<std::vector<T,A>>& data = (static_cast<const C*>(r)->*m_fn);
                return BufferData{ data.get().data(), data.get().size()*sizeof(T), data.revision()};
            }
        };

        template <typename BO, typename C, typename T, size_t N>
        struct MBA_StdArray : public BO {
            typedef std::array<T,N> (C::*FN);
            FN m_fn;
            
            MBA_StdArray(FN fn, std::string_view name, Pipeline* parent, const std::source_location& sl) : 
                BO(name, parent, sl), m_fn(fn)
            {
            }
            
            BufferData get(const Rendered* r) const
            {
                if(!r)
                    return {};
                const std::array<T,N>& data = (static_cast<const C*>(r)->*m_fn);
                return BufferData{ data.data(), N*sizeof(T) };
            }
        };


        template <typename BO, typename C, typename T, size_t N>
        struct MBA_MutableStdArray : public BO {
            typedef Mutable<std::array<T,N>> (C::*FN);
            FN m_fn;
            
            MBA_MutableStdArray(FN fn, std::string_view name, Pipeline* parent, const std::source_location& sl) : 
                BO(name, parent, sl), m_fn(fn)
            {
            }
            
            BufferData get(const Rendered* r) const
            {
                if(!r)
                    return {};
                const Mutable<std::array<T,N>>& data = (static_cast<const C*>(r)->*m_fn);
                return BufferData{ data.get().data(), N*sizeof(T), data.revision() };
            }
        };

        template <typename BO, typename C, typename T, size_t N>
        struct MBA_CArray : public BO {
            typedef T (C::*FN)[N];
            FN m_fn;
            
            MBA_CArray(FN fn, std::string_view name, Pipeline* parent, const std::source_location& sl) : 
                BO(name, parent, sl), m_fn(fn)
            {
            }
            
            BufferData get(const Rendered* r) const
            {
                if(!r)
                    return {};
                const T* data = (static_cast<const C*>(r)->*m_fn);
                return BufferData{ data, N*sizeof(T) };
            }
        };


        template <typename BO, typename T, size_t N>
        struct XBA_CArray : public BO {
            typedef const T (&P)[N];
            P m_fn;
            
            XBA_CArray(P fn, std::string_view name, Pipeline* parent, const std::source_location& sl) : 
                BO(name, parent, sl), m_fn(fn)
            {
            }
            
            BufferData get(const Rendered*) const
            {
                return BufferData{ m_fn, N*sizeof(T) };
            }
        };

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template <typename C>
        class TypedPipelineBuilder : public Pipeline::Writer {
        public:
            
            TypedPipelineBuilder(TypedPipeline<C>*p) : Pipeline::Writer(p), m_myPipeline(p) 
            {
            }
  

#if 0
            /*! \brief Creates an uniform buffer whose data is SHARED with ALL instances of the pipeline 
            */
            template <typename G>
            auto        shared_uniform(std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return uniform<G>(DataActivity::COMMON, n, loc, sl);
            }
            
            /*! \brief Creates an uniform buffer whose data is STATIC (unchanging) for a specific instance of the rendered object
            */
            template <typename G>
            auto        static_uniform(std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return uniform<G>(DataActivity::STATIC, n, loc, sl);
            }

            /*! \brief Creates an uniform buffer whose data is expected to change from time to time
            */
            template <typename G>
            auto        dynamic_uniform(std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return uniform<G>(DataActivity::DYNAMIC, n, loc, sl);
            }

            /*! \brief Creates an uniform buffer whose data is expected to change with every render!
            */
            template <typename G>
            auto        refresh_uniform(std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return uniform<G>(DataActivity::REFRESH, n, loc, sl);
            }

            /*! \brief Creates an vertex buffer whose data is SHARED with ALL instances of the pipeline 
            */
            template <typename G>
            auto        shared_vertex(std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<G>(DataActivity::COMMON, n, loc, sl);
            }

            /*! \brief Creates an vertex buffer whose data is STATIC (unchanging) for a specific instance of the rendered object
            */
            template <typename G>
            auto        static_vertex(std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<G>(DataActivity::STATIC, n, loc, sl);
            }

            /*! \brief Creates an vertex buffer whose data is expected to change from time to time
            */
            template <typename G>
            auto        dynamic_vertex(std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<G>(DataActivity::DYNAMIC, n, loc, sl);
            }

            /*! \brief Creates an vertex buffer whose data is expected to change with every render!
            */
            template <typename G>
            auto        refresh_vertex(std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<G>(DataActivity::REFRESH, n, loc, sl);
            }
#endif

            //  --------------------------------------------------------------

            template <typename T, size_t N>
            void        common_index(const T (&p)[N], std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new XBA_CArray<IndexBufferObjectInfo, T, N>(p, n, m_myPipeline, sl), DataActivity::COMMON, loc);
            }


            template <typename T, size_t N>
            void        static_index(std::array<T,N> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_StdArray<IndexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::STATIC, loc);
            }

            template <typename T, typename A>
            void        static_index(std::vector<T,A> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_StdVector<IndexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::STATIC, loc);
            }
            
            template <typename T, size_t N>
            void        static_index(Mutable<std::array<T,N>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_MutableStdArray<IndexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::STATIC, loc);
            }

            template <typename T, typename A>
            void        static_index(Mutable<std::vector<T,A>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_MutableStdVector<IndexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::STATIC, loc);
            }


            template <typename T, size_t N>
            void        dynamic_index(Mutable<std::array<T,N>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_MutableStdArray<IndexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::DYNAMIC, loc);
            }

            template <typename T, typename A>
            void        dynamic_index(Mutable<std::vector<T,A>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_MutableStdVector<IndexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::DYNAMIC, loc);
            }

            template <typename T, size_t N>
            void        refresh_index(std::array<T,N> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_StdArray<IndexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::REFRESH, loc);
            }

            template <typename T, typename A>
            void        refresh_index(std::vector<T,A> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_StdVector<IndexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::REFRESH, loc);
            }
            
            template <typename T, size_t N>
            void        refresh_index(Mutable<std::array<T,N>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_MutableStdArray<IndexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::REFRESH, loc);
            }

            template <typename T, typename A>
            void        refresh_index(Mutable<std::vector<T,A>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                index<T>(new MBA_MutableStdVector<IndexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::REFRESH, loc);
            }


            //  --------------------------------------------------------------

            template <typename T, size_t N>
            PipelineBuilder::VBO<T>        common_vertex(const T (&p)[N], std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new XBA_CArray<VertexBufferObjectInfo, T, N>(p, n, m_myPipeline, sl), DataActivity::COMMON, loc);
            }

            template <typename T, size_t N>
            PipelineBuilder::VBO<T>        static_vertex(std::array<T,N> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_StdArray<VertexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::STATIC, loc);
            }

            template <typename T, typename A>
            PipelineBuilder::VBO<T>        static_vertex(std::vector<T,A> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_StdVector<VertexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::STATIC, loc);
            }
            
            template <typename T, size_t N>
            PipelineBuilder::VBO<T>        static_vertex(Mutable<std::array<T,N>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_MutableStdArray<VertexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::STATIC, loc);
            }

            template <typename T, typename A>
            PipelineBuilder::VBO<T>        static_vertex(Mutable<std::vector<T,A>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_MutableStdVector<VertexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::STATIC, loc);
            }

            template <typename T, size_t N>
            PipelineBuilder::VBO<T>        dynamic_vertex(Mutable<std::array<T,N>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_MutableStdArray<VertexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::DYNAMIC, loc);
            }

            template <typename T, typename A>
            PipelineBuilder::VBO<T>        dynamic_vertex(Mutable<std::vector<T,A>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_MutableStdVector<VertexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::DYNAMIC, loc);
            }

            template <typename T, size_t N>
            PipelineBuilder::VBO<T>        refresh_vertex(std::array<T,N> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_StdArray<VertexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::REFRESH, loc);
            }

            template <typename T, typename A>
            PipelineBuilder::VBO<T>        refresh_vertex(std::vector<T,A> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_StdVector<VertexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::REFRESH, loc);
            }


            template <typename T, size_t N>
            PipelineBuilder::VBO<T>        refresh_vertex(Mutable<std::array<T,N>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_MutableStdArray<VertexBufferObjectInfo, C, T, N>(p, n, m_myPipeline, sl), DataActivity::REFRESH, loc);
            }

            template <typename T, typename A>
            PipelineBuilder::VBO<T>        refresh_vertex(Mutable<std::vector<T,A>> C::*p, std::string_view n, uint32_t loc=UINT32_MAX, const std::source_location&sl = std::source_location::current())
            {
                return vertex<T>(new MBA_MutableStdVector<VertexBufferObjectInfo, C, T, A>(p, n, m_myPipeline, sl), DataActivity::REFRESH, loc);
            }

            //  --------------------------------------------------------------

        private:
        
            template <typename T>
            void        index(IndexBufferObjectInfo* buffer, DataActivity::enum_t act, uint32_t loc)
            {
                buffer -> set_data_activity(act);
                buffer -> set_index_type(index_type<T>());
            }

            template <typename T>
            void        uniform(UniformBufferObjectInfo* buffer, DataActivity::enum_t act, uint32_t loc)
            {
            }
            
            template <typename V>
            PipelineBuilder::VBO<V> vertex(VertexBufferObjectInfo* buffer, DataActivity::enum_t act, uint32_t loc)
            {
                buffer -> set_data_activity(act);
                return PipelineBuilder::VBO<V>(this, 
                    [buffer](uint32_t loc)
                    { 
                        buffer->set_location(loc);
                    }
                );
            }
            
        
            TypedPipeline<C>*   m_myPipeline = nullptr;
        };
        

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template <typename C>
        class RenderedInfo::Writer : public MetaObjectInfo::Writer<C> {
        public:
            Writer(RenderedInfo* renderInfo) : MetaObjectInfo::Writer<C>(renderInfo), m_rendered(renderInfo)
            {
            }
            
            Writer(RenderedInfo& renderInfo) : Writer(&renderInfo)
            {
            }
            
            
            TypedPipelineBuilder<C>   pipeline(std::string_view name=std::string_view(), const std::source_location&sl=std::source_location::current())
            {
                TypedPipeline<C>*       tp  = new TypedPipeline<C>( name, m_rendered, sl);
                if(m_rendered && !m_rendered->m_primary)
                    m_rendered->m_primary   = tp;
                return TypedPipelineBuilder<C>(tp);
            }
            
        private:
            RenderedInfo*       m_rendered;
        };

        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        template <typename C>
        class Render3DInfo::Writer : public RenderedInfo::Writer<C> {
        public:
            Writer(Render3DInfo* renderInfo) : RenderedInfo::Writer<C>(renderInfo)
            {
            }
            
            Writer(Render3DInfo& renderInfo) : Writer(&renderInfo)
            {
            }
        };


    }
}
