////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/ArgDeducer.hpp>
#include <yq/meta/MetaObjectInfoWriter.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/api/TachyonData.hpp>
#include <yt/api/Interface.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {

    class PBXDispatch {
    public:
        class Writer;

        const PostInfo*     post() const { return m_post; }
    
            //! Lets us know the syntax being invoked
        virtual const char* debug_string() const = 0;
        std::string_view    name() const { return m_name; }
        
    protected:
        const PostInfo*     m_post          = nullptr;
        std::string_view    m_name;
        
        friend class Tachyon;
        PBXDispatch(){}
        virtual ~PBXDispatch(){}
        
        virtual bool        dispatch(Tachyon*, const PostCPtr&) const = 0;
    };
    
    template <class C, SomePost P>
    class PBXDispatch_VoidCRef : public PBXDispatch {
    public:
        typedef void (C::*FN)(const P&);
        FN              m_fn;
        
        PBXDispatch_VoidCRef(FN fn) : PBXDispatch(), m_fn(fn)
        {
            m_post      = &meta<P>();
        }
        
        bool  dispatch(Tachyon *tac, const PostCPtr& pp) const override
        {
            C*  c   = dynamic_cast<C*>(tac);
            if(!c)
                return false;
            (c->*m_fn)(static_cast<const P&>(*pp));
            return true;
        }

        const char* debug_string() const override
        {
            return "void(C::*)(const P&)";
        }
    };
    
    template <class C, SomePost P>
    class PBXDispatch_BoolCRef : public PBXDispatch {
    public:
        typedef bool (C::*FN)(const P&);
        FN              m_fn;
        
        PBXDispatch_BoolCRef(FN fn) : PBXDispatch(), m_fn(fn)
        {
            m_post      = &meta<P>();
        }
        
        bool  dispatch(Tachyon *pbx, const PostCPtr& pp) const override
        {
            C*  c   = dynamic_cast<C&>(pbx);
            if(!c)
                return false;
            return (c->*m_fn)(static_cast<const P&>(*pp));
        }

        const char* debug_string() const override
        {
            return "bool(C::*)(const P&)";
        }
    };
    
    template <class C, SomePost P>
    class PBXDispatch_VoidCPtr : public PBXDispatch {
    public:
        typedef void (C::*FN)(const Ref<const P>&);
        FN              m_fn;
        
        PBXDispatch_VoidCPtr(FN fn) : PBXDispatch(), m_fn(fn)
        {
            m_post      = &meta<P>();
        }
        
        bool  dispatch(Tachyon *pbx, const PostCPtr& pp) const override
        {
            C*  c   = dynamic_cast<C*>(pbx);
            if(!c)
                return false;
            Ref<const P>    ppp(static_cast<const P*>(pp.ptr()));
            (c->*m_fn)(ppp);
            return true;
        }

        const char* debug_string() const override
        {
            return "void(C::*)(const Ref<P>&)";
        }
    };

    template <class C, SomePost P>
    class PBXDispatch_BoolCPtr : public PBXDispatch {
    public:
        typedef bool (C::*FN)(const Ref<const P>&);
        FN              m_fn;
        
        PBXDispatch_BoolCPtr(FN fn) : PBXDispatch(), m_fn(fn)
        {
            m_post      = &meta<P>();
        }
        
        bool  dispatch(Tachyon &pbx, const PostCPtr& pp) const override
        {
            C*  c   = dynamic_cast<C*>(pbx);
            if(!c)
                return false;
            Ref<const P>    ppp(static_cast<const P*>(pp.ptr()));
            return (c.*m_fn)(ppp);
        }

        const char* debug_string() const override
        {
            return "bool(C::*)(const Ref<P>&)";
        }
    };

    class PBXDispatch::Writer {
    public:
        Writer(PBXDispatch* pbx=nullptr) : m_pbx(pbx) {}
        
        Writer& name(std::string_view v) 
        {
            if(m_pbx){
                m_pbx -> m_name = v;
            }
            return *this;
        }
        
    private:
        PBXDispatch*    m_pbx;
    };


    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////


    /*! \brief Writer of manager information
    */
    template <typename C>
    class TachyonInfo::Writer : public ObjectInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(TachyonInfo* theInfo) : ObjectInfo::Writer<C>(theInfo), m_meta(theInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(TachyonInfo& theInfo) : Writer(&theInfo)
        {
        }

        template <SomePost P, class C2=C>
        PBXDispatch::Writer    slot(void (C2::*fn)(const P&))
        {
            static_assert(std::derived_from<C,C2>, "Incompatible Tachyon types, need inheritance");
            return slot<P,C2>(UNSAFE, fn);
        }

        template <SomePost P, class C2=C>
        PBXDispatch::Writer    slot(unsafe_k, void (C2::*fn)(const P&))
        {
            if(m_meta && Meta::thread_safe_write()){
                PBXDispatch*    ret = new PBXDispatch_VoidCRef<C2,P>(fn);
                m_meta -> add_dispatch(ret);
                return ret;
            }
            return {};
        }
        
        template <SomePost P, class C2=C>
        PBXDispatch::Writer    slot(bool (C2::*fn)(const P&))
        {
            static_assert(std::derived_from<C,C2>, "Incompatible Tachyon types, need inheritance");
            return slot<P,C2>(UNSAFE, fn);
        }
        
        template <SomePost P, class C2=C>
        PBXDispatch::Writer    slot(unsafe_k, bool (C2::*fn)(const P&))
        {
            if(m_meta && Meta::thread_safe_write()){
                PBXDispatch*    ret = new PBXDispatch_BoolCRef<C2,P>(fn);
                m_meta -> add_dispatch(ret);
                return ret;
            }
            return {};
        }
        
        
        template <SomePost P, SomeTachyon C2=C>
        PBXDispatch::Writer    slot(void (C2::*fn)(const Ref<const P>&))
        {
            static_assert(std::derived_from<C,C2>, "Incompatible Tachyon types, need inheritance");
            return slot<P,C2>(UNSAFE, fn);
        }
        
        template <SomePost P, SomeTachyon C2=C>
        PBXDispatch::Writer    slot(unsafe_k, void (C2::*fn)(const Ref<const P>&))
        {
            if(m_meta && Meta::thread_safe_write()){
                PBXDispatch*    ret = new PBXDispatch_VoidCPtr<C2,P>(fn);
                m_meta -> add_dispatch(ret);
                return ret;
            }
            return {};
        }

        template <SomePost P, SomeTachyon C2=C>
        PBXDispatch::Writer    slot(bool (C2::*fn)(const Ref<const P>&))
        {
            static_assert(std::derived_from<C,C2>, "Incompatible Tachyon types, need inheritance");
            return slot<P,C2>(UNSAFE, fn);
        }
        
        template <SomePost P, SomeTachyon C2=C>
        PBXDispatch::Writer    slot(unsafe_k, bool (C2::*fn)(const Ref<const P>&))
        {
            if(m_meta && Meta::thread_safe_write()){
                PBXDispatch*    ret = new PBXDispatch_BoolCPtr<C2,P>(fn);
                m_meta -> add_dispatch(ret);
                return ret;
            }
            return {};
        }

        template <Interface I>
        void    interface()
        {
            if(m_meta && Meta::thread_safe_write()){
                m_meta -> add_interface(&meta<I>());
            }
        }
        
        void    execution(Execution ex)
        {
            if(m_meta && Meta::thread_safe_write()){
                m_meta -> m_execution = ex;
            }
        }
        
        
    private:
        TachyonInfo* m_meta;
    };


    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////
    
    template <typename C>
    class Tachyon::Fixer : public ObjectFixer<C> {
    public:
    
        using snap_fn   = decltype(args::deduce(&C::snap));
        using data_t    = typename C::MyData;
        using snap_t    = typename snap_fn::arg_t;

        Fixer(std::string_view zName, typename C::MyBase::MyInfo& base, const std::source_location& sl=std::source_location::current()) : 
            ObjectFixer<C>(zName, base, sl)
        {
        }
        
        virtual TachyonSnapPtr   create_snap(const Tachyon& t) const override 
        {
            Ref<snap_t>     snap    = new snap_t;
            static_cast<const C&>(t).snap(*snap);
            return snap;
        }
        
        virtual TachyonDataPtr   create_data() const override
        {
            return new data_t();
        }
        
        virtual void    finalize_data(const Tachyon&t, TachyonData&d) const    
        {
            static_cast<const C&>(t).finalize(static_cast<data_t&>(d));
        }
    };
}
