////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tbb/spin_rw_mutex.h>

#include <yq/unit/declare.hpp>
#include <yq/vkqt/XTachyon.hpp>
#include <yq/vkqt/qmeta/typed_id.hpp>

namespace yq::tachyon {
    class MTachyon;

    class MTachyonMeta : public TachyonMeta {
    public:
        template <typename> class Writer;

        MTachyonMeta(std::string_view zName, TachyonMeta& base, const std::source_location& sl=std::source_location::current());
        
        virtual MTachyon*           create(TypedID) const { return nullptr; }
        
        static const MTachyonMeta*  find(id_t);
        static const MTachyonMeta*  find(const TachyonMeta&);
        
    private:
    
        void    add_managed(const TachyonMeta&);
    
    
        struct Repo;
        static Repo& repo();
    };

    /*! \brief Is/Manages a tachyon
    
        We derive from both so signals/slots *AND* the post system work.
        Overall, the inheritance should mimic the tachyon's (or if it's an 
        interface, from that).  The convention will be "M${Name}".
        
        \note This *might* be pulled into vkqt.
    */
    class MTachyon : public XTachyon<QObject, Tachyon> {
    public:
        template <typename> class Fixer;

    private:
        YQ_TACHYON_META(MTachyonMeta)
        YQ_TACHYON_FIXER(Fixer)
        YQ_TACHYON_DECLARE(MTachyon, Tachyon)
        Q_OBJECT
    public:

        MTachyon(TypedID);
        virtual ~MTachyon();
        
        static void init_meta();

        //! Other's children
        //! \note COPY the vector if retention is needed, the underlying reference 
        //! may otherwise vanish unpredictably
        const std::vector<TypedID>&     ochildren() const;
        TachyonID                       oid() const { return { m_otherID.id }; }
        QString                         oname() const;
        TypedID                         oparent() const;
        bool                            opaused() const;
        //! Unsafe pointer to what we're following (may vanish), may be null
        Tachyon*                        opointer() const;
        uint64_t                        orevision() const;
        bool                            orunning() const;
        
        const TachyonSnap*              osnap() const;
        bool                            ostarted() const;
        bool                            oteardown() const;
        unit::Second                    otime() const;
        //! ID of what we're following
        TypedID                         otyped() const { return m_otherID; }

    public slots:
    
        //! Sets the name on the other object
        //! \note This may take several ticks to reflect in the oname() call.
        void                setOName(const QString&);
        
        //! Sets the parent on the other object
        //! \note This may take several ticks to reflect in the oparent() call.
        void                setOParent(TypedID);

    signals:
        void    changed();

    protected:
    
        const TypedID   m_otherID;

        virtual Execution   tick(const Context&) override;
        virtual Execution   paused(const Context&) override;
        virtual Execution   setup(const Context&) override;
        virtual Execution   teardown(const Context&) override;
        
    private:
    
        void    _poll();
    
        enum class X {};
    
        uint64_t        m_otherRevision = 0;
        Flags<X>        m_flags;
    };
}
