#if 0
<<'SKIP';
#endif
/*
----------------------------------------------------------------------

    ppport.h -- Perl/Pollution/Portability Version 3.11_05

    Automatically created by Devel::PPPort running under perl 5.008008.

    Version 3.x, Copyright (c) 2004-2007, Marcus Holland-Moritz.

    Version 2.x, Copyright (C) 2001, Paul Marquess.

    Version 1.x, Copyright (C) 1999, Kenneth Albanowski.

    This program is free software; you can redistribute it and/or
    modify it under the same terms as Perl itself.

----------------------------------------------------------------------

SKIP
if (@ARGV && $ARGV[0] eq '--unstrip') {
  eval { require Devel::PPPort };
  $@ and die "Cannot require Devel::PPPort, please install.\n";
  if ($Devel::PPPort::VERSION < 3.1105) {
    die "ppport.h was originally generated with Devel::PPPort 3.1105.\n"
      . "Your Devel::PPPort is only version $Devel::PPPort::VERSION.\n"
      . "Please install a newer version, or --unstrip will not work.\n";
  }
  Devel::PPPort::WriteFile($0);
  exit 0;
}
print <<END;

Sorry, but this is a stripped version of $0.

To be able to use its original script and doc functionality,
please try to regenerate this file using:

  $^X $0 --unstrip

END
__DATA__*/
#ifndef _P_P_PORTABILITY_H_
#define _P_P_PORTABILITY_H_
#ifndef DPPP_NAMESPACE
#define DPPP_NAMESPACE DPPP_
#endif
#define DPPP_CAT2(x,y) CAT2(x,y)
#define DPPP_(name) DPPP_CAT2(DPPP_NAMESPACE, name)
#ifndef PERL_REVISION
#if !defined(__PATCHLEVEL_H_INCLUDED__) && !(defined(PATCHLEVEL) && defined(SUBVERSION))
#define PERL_PATCHLEVEL_H_IMPLICIT
#include <patchlevel.h>
#endif
#if !(defined(PERL_VERSION) || (defined(SUBVERSION) && defined(PATCHLEVEL)))
#include <could_not_find_Perl_patchlevel.h>
#endif
#ifndef PERL_REVISION
#define PERL_REVISION (5)
#define PERL_VERSION PATCHLEVEL
#define PERL_SUBVERSION SUBVERSION
#endif
#endif
#define _dpppDEC2BCD(dec) ((((dec)/100)<<8)|((((dec)%100)/10)<<4)|((dec)%10))
#define PERL_BCDVERSION ((_dpppDEC2BCD(PERL_REVISION)<<24)|(_dpppDEC2BCD(PERL_VERSION)<<12)|_dpppDEC2BCD(PERL_SUBVERSION))
#if PERL_REVISION != 5
#error ppport.h only works with Perl version 5
#endif
#ifdef I_LIMITS
#include <limits.h>
#endif
#ifndef PERL_UCHAR_MIN
#define PERL_UCHAR_MIN ((unsigned char)0)
#endif
#ifndef PERL_UCHAR_MAX
#ifdef UCHAR_MAX
#define PERL_UCHAR_MAX ((unsigned char)UCHAR_MAX)
#else
#ifdef MAXUCHAR
#define PERL_UCHAR_MAX ((unsigned char)MAXUCHAR)
#else
#define PERL_UCHAR_MAX ((unsigned char)~(unsigned)0)
#endif
#endif
#endif
#ifndef PERL_USHORT_MIN
#define PERL_USHORT_MIN ((unsigned short)0)
#endif
#ifndef PERL_USHORT_MAX
#ifdef USHORT_MAX
#define PERL_USHORT_MAX ((unsigned short)USHORT_MAX)
#else
#ifdef MAXUSHORT
#define PERL_USHORT_MAX ((unsigned short)MAXUSHORT)
#else
#ifdef USHRT_MAX
#define PERL_USHORT_MAX ((unsigned short)USHRT_MAX)
#else
#define PERL_USHORT_MAX ((unsigned short)~(unsigned)0)
#endif
#endif
#endif
#endif
#ifndef PERL_SHORT_MAX
#ifdef SHORT_MAX
#define PERL_SHORT_MAX ((short)SHORT_MAX)
#else
#ifdef MAXSHORT
#define PERL_SHORT_MAX ((short)MAXSHORT)
#else
#ifdef SHRT_MAX
#define PERL_SHORT_MAX ((short)SHRT_MAX)
#else
#define PERL_SHORT_MAX ((short) (PERL_USHORT_MAX >> 1))
#endif
#endif
#endif
#endif
#ifndef PERL_SHORT_MIN
#ifdef SHORT_MIN
#define PERL_SHORT_MIN ((short)SHORT_MIN)
#else
#ifdef MINSHORT
#define PERL_SHORT_MIN ((short)MINSHORT)
#else
#ifdef SHRT_MIN
#define PERL_SHORT_MIN ((short)SHRT_MIN)
#else
#define PERL_SHORT_MIN (-PERL_SHORT_MAX - ((3 & -1) == 3))
#endif
#endif
#endif
#endif
#ifndef PERL_UINT_MAX
#ifdef UINT_MAX
#define PERL_UINT_MAX ((unsigned int)UINT_MAX)
#else
#ifdef MAXUINT
#define PERL_UINT_MAX ((unsigned int)MAXUINT)
#else
#define PERL_UINT_MAX (~(unsigned int)0)
#endif
#endif
#endif
#ifndef PERL_UINT_MIN
#define PERL_UINT_MIN ((unsigned int)0)
#endif
#ifndef PERL_INT_MAX
#ifdef INT_MAX
#define PERL_INT_MAX ((int)INT_MAX)
#else
#ifdef MAXINT
#define PERL_INT_MAX ((int)MAXINT)
#else
#define PERL_INT_MAX ((int)(PERL_UINT_MAX >> 1))
#endif
#endif
#endif
#ifndef PERL_INT_MIN
#ifdef INT_MIN
#define PERL_INT_MIN ((int)INT_MIN)
#else
#ifdef MININT
#define PERL_INT_MIN ((int)MININT)
#else
#define PERL_INT_MIN (-PERL_INT_MAX - ((3 & -1) == 3))
#endif
#endif
#endif
#ifndef PERL_ULONG_MAX
#ifdef ULONG_MAX
#define PERL_ULONG_MAX ((unsigned long)ULONG_MAX)
#else
#ifdef MAXULONG
#define PERL_ULONG_MAX ((unsigned long)MAXULONG)
#else
#define PERL_ULONG_MAX (~(unsigned long)0)
#endif
#endif
#endif
#ifndef PERL_ULONG_MIN
#define PERL_ULONG_MIN ((unsigned long)0L)
#endif
#ifndef PERL_LONG_MAX
#ifdef LONG_MAX
#define PERL_LONG_MAX ((long)LONG_MAX)
#else
#ifdef MAXLONG
#define PERL_LONG_MAX ((long)MAXLONG)
#else
#define PERL_LONG_MAX ((long) (PERL_ULONG_MAX >> 1))
#endif
#endif
#endif
#ifndef PERL_LONG_MIN
#ifdef LONG_MIN
#define PERL_LONG_MIN ((long)LONG_MIN)
#else
#ifdef MINLONG
#define PERL_LONG_MIN ((long)MINLONG)
#else
#define PERL_LONG_MIN (-PERL_LONG_MAX - ((3 & -1) == 3))
#endif
#endif
#endif
#if defined(HAS_QUAD) && (defined(convex) || defined(uts))
#ifndef PERL_UQUAD_MAX
#ifdef ULONGLONG_MAX
#define PERL_UQUAD_MAX ((unsigned long long)ULONGLONG_MAX)
#else
#ifdef MAXULONGLONG
#define PERL_UQUAD_MAX ((unsigned long long)MAXULONGLONG)
#else
#define PERL_UQUAD_MAX (~(unsigned long long)0)
#endif
#endif
#endif
#ifndef PERL_UQUAD_MIN
#define PERL_UQUAD_MIN ((unsigned long long)0L)
#endif
#ifndef PERL_QUAD_MAX
#ifdef LONGLONG_MAX
#define PERL_QUAD_MAX ((long long)LONGLONG_MAX)
#else
#ifdef MAXLONGLONG
#define PERL_QUAD_MAX ((long long)MAXLONGLONG)
#else
#define PERL_QUAD_MAX ((long long) (PERL_UQUAD_MAX >> 1))
#endif
#endif
#endif
#ifndef PERL_QUAD_MIN
#ifdef LONGLONG_MIN
#define PERL_QUAD_MIN ((long long)LONGLONG_MIN)
#else
#ifdef MINLONGLONG
#define PERL_QUAD_MIN ((long long)MINLONGLONG)
#else
#define PERL_QUAD_MIN (-PERL_QUAD_MAX - ((3 & -1) == 3))
#endif
#endif
#endif
#endif
#ifdef HAS_QUAD
#ifdef cray
#ifndef IVTYPE
#define IVTYPE int
#endif
#ifndef IV_MIN
#define IV_MIN PERL_INT_MIN
#endif
#ifndef IV_MAX
#define IV_MAX PERL_INT_MAX
#endif
#ifndef UV_MIN
#define UV_MIN PERL_UINT_MIN
#endif
#ifndef UV_MAX
#define UV_MAX PERL_UINT_MAX
#endif
#ifdef INTSIZE
#ifndef IVSIZE
#define IVSIZE INTSIZE
#endif
#endif
#else
#if defined(convex) || defined(uts)
#ifndef IVTYPE
#define IVTYPE long long
#endif
#ifndef IV_MIN
#define IV_MIN PERL_QUAD_MIN
#endif
#ifndef IV_MAX
#define IV_MAX PERL_QUAD_MAX
#endif
#ifndef UV_MIN
#define UV_MIN PERL_UQUAD_MIN
#endif
#ifndef UV_MAX
#define UV_MAX PERL_UQUAD_MAX
#endif
#ifdef LONGLONGSIZE
#ifndef IVSIZE
#define IVSIZE LONGLONGSIZE
#endif
#endif
#else
#ifndef IVTYPE
#define IVTYPE long
#endif
#ifndef IV_MIN
#define IV_MIN PERL_LONG_MIN
#endif
#ifndef IV_MAX
#define IV_MAX PERL_LONG_MAX
#endif
#ifndef UV_MIN
#define UV_MIN PERL_ULONG_MIN
#endif
#ifndef UV_MAX
#define UV_MAX PERL_ULONG_MAX
#endif
#ifdef LONGSIZE
#ifndef IVSIZE
#define IVSIZE LONGSIZE
#endif
#endif
#endif
#endif
#ifndef IVSIZE
#define IVSIZE 8
#endif
#ifndef PERL_QUAD_MIN
#define PERL_QUAD_MIN IV_MIN
#endif
#ifndef PERL_QUAD_MAX
#define PERL_QUAD_MAX IV_MAX
#endif
#ifndef PERL_UQUAD_MIN
#define PERL_UQUAD_MIN UV_MIN
#endif
#ifndef PERL_UQUAD_MAX
#define PERL_UQUAD_MAX UV_MAX
#endif
#else
#ifndef IVTYPE
#define IVTYPE long
#endif
#ifndef IV_MIN
#define IV_MIN PERL_LONG_MIN
#endif
#ifndef IV_MAX
#define IV_MAX PERL_LONG_MAX
#endif
#ifndef UV_MIN
#define UV_MIN PERL_ULONG_MIN
#endif
#ifndef UV_MAX
#define UV_MAX PERL_ULONG_MAX
#endif
#endif
#ifndef IVSIZE
#ifdef LONGSIZE
#define IVSIZE LONGSIZE
#else
#define IVSIZE 4
#endif
#endif
#ifndef UVTYPE
#define UVTYPE unsigned IVTYPE
#endif
#ifndef UVSIZE
#define UVSIZE IVSIZE
#endif
#ifndef sv_setuv
#define sv_setuv(sv, uv) \
STMT_START { \
UV TeMpUv = uv; \
if (TeMpUv <= IV_MAX) \
sv_setiv(sv, TeMpUv); \
else \
sv_setnv(sv, (double)TeMpUv); \
} STMT_END
#endif
#ifndef newSVuv
#define newSVuv(uv) ((uv) <= IV_MAX ? newSViv((IV)uv) : newSVnv((NV)uv))
#endif
#ifndef sv_2uv
#define sv_2uv(sv) ((PL_Sv = (sv)), (UV) (SvNOK(PL_Sv) ? SvNV(PL_Sv) : sv_2nv(PL_Sv)))
#endif
#ifndef SvUVX
#define SvUVX(sv) ((UV)SvIVX(sv))
#endif
#ifndef SvUVXx
#define SvUVXx(sv) SvUVX(sv)
#endif
#ifndef SvUV
#define SvUV(sv) (SvIOK(sv) ? SvUVX(sv) : sv_2uv(sv))
#endif
#ifndef SvUVx
#define SvUVx(sv) ((PL_Sv = (sv)), SvUV(PL_Sv))
#endif
#ifndef sv_uv
#define sv_uv(sv) SvUVx(sv)
#endif
#if !defined(SvUOK) && defined(SvIOK_UV)
#define SvUOK(sv) SvIOK_UV(sv)
#endif
#ifndef XST_mUV
#define XST_mUV(i,v) (ST(i) = sv_2mortal(newSVuv(v)) )
#endif
#ifndef XSRETURN_UV
#define XSRETURN_UV(v) STMT_START { XST_mUV(0,v); XSRETURN(1); } STMT_END
#endif
#ifndef PUSHu
#define PUSHu(u) STMT_START { sv_setuv(TARG, (UV)(u)); PUSHTARG; } STMT_END
#endif
#ifndef XPUSHu
#define XPUSHu(u) STMT_START { sv_setuv(TARG, (UV)(u)); XPUSHTARG; } STMT_END
#endif
#ifdef HAS_MEMCMP
#ifndef memNE
#define memNE(s1,s2,l) (memcmp(s1,s2,l))
#endif
#ifndef memEQ
#define memEQ(s1,s2,l) (!memcmp(s1,s2,l))
#endif
#else
#ifndef memNE
#define memNE(s1,s2,l) (bcmp(s1,s2,l))
#endif
#ifndef memEQ
#define memEQ(s1,s2,l) (!bcmp(s1,s2,l))
#endif
#endif
#ifndef MoveD
#define MoveD(s,d,n,t) memmove((char*)(d),(char*)(s), (n) * sizeof(t))
#endif
#ifndef CopyD
#define CopyD(s,d,n,t) memcpy((char*)(d),(char*)(s), (n) * sizeof(t))
#endif
#ifdef HAS_MEMSET
#ifndef ZeroD
#define ZeroD(d,n,t) memzero((char*)(d), (n) * sizeof(t))
#endif
#else
#ifndef ZeroD
#define ZeroD(d,n,t) ((void)memzero((char*)(d), (n) * sizeof(t)), d)
#endif
#endif
#ifndef PoisonWith
#define PoisonWith(d,n,t,b) (void)memset((char*)(d), (U8)(b), (n) * sizeof(t))
#endif
#ifndef PoisonNew
#define PoisonNew(d,n,t) PoisonWith(d,n,t,0xAB)
#endif
#ifndef PoisonFree
#define PoisonFree(d,n,t) PoisonWith(d,n,t,0xEF)
#endif
#ifndef Poison
#define Poison(d,n,t) PoisonFree(d,n,t)
#endif
#ifndef Newx
#define Newx(v,n,t) New(0,v,n,t)
#endif
#ifndef Newxc
#define Newxc(v,n,t,c) Newc(0,v,n,t,c)
#endif
#ifndef Newxz
#define Newxz(v,n,t) Newz(0,v,n,t)
#endif
#ifndef PERL_UNUSED_DECL
#ifdef HASATTRIBUTE
#if (defined(__GNUC__) && defined(__cplusplus)) || defined(__INTEL_COMPILER)
#define PERL_UNUSED_DECL
#else
#define PERL_UNUSED_DECL __attribute__((unused))
#endif
#else
#define PERL_UNUSED_DECL
#endif
#endif
#ifndef PERL_UNUSED_ARG
#if defined(lint) && defined(S_SPLINT_S)
#include <note.h>
#define PERL_UNUSED_ARG(x) NOTE(ARGUNUSED(x))
#else
#define PERL_UNUSED_ARG(x) ((void)x)
#endif
#endif
#ifndef PERL_UNUSED_VAR
#define PERL_UNUSED_VAR(x) ((void)x)
#endif
#ifndef PERL_UNUSED_CONTEXT
#ifdef USE_ITHREADS
#define PERL_UNUSED_CONTEXT PERL_UNUSED_ARG(my_perl)
#else
#define PERL_UNUSED_CONTEXT
#endif
#endif
#ifndef NOOP
#define NOOP (void)0
#endif
#ifndef dNOOP
#define dNOOP extern int  Perl___notused PERL_UNUSED_DECL
#endif
#ifndef NVTYPE
#if defined(USE_LONG_DOUBLE) && defined(HAS_LONG_DOUBLE)
#define NVTYPE long double
#else
#define NVTYPE double
#endif
typedef NVTYPE NV;
#endif
#ifndef INT2PTR
#if (IVSIZE == PTRSIZE) && (UVSIZE == PTRSIZE)
#define PTRV UV
#define INT2PTR(any,d) (any)(d)
#else
#if PTRSIZE == LONGSIZE
#define PTRV unsigned long
#else
#define PTRV unsigned
#endif
#define INT2PTR(any,d) (any)(PTRV)(d)
#endif
#define NUM2PTR(any,d) (any)(PTRV)(d)
#define PTR2IV(p) INT2PTR(IV,p)
#define PTR2UV(p) INT2PTR(UV,p)
#define PTR2NV(p) NUM2PTR(NV,p)
#if PTRSIZE == LONGSIZE
#define PTR2ul(p) (unsigned long)(p)
#else
#define PTR2ul(p) INT2PTR(unsigned long,p)
#endif
#endif
#undef START_EXTERN_C
#undef END_EXTERN_C
#undef EXTERN_C
#ifdef __cplusplus
#define START_EXTERN_C extern "C" {
#define END_EXTERN_C }
#define EXTERN_C extern "C"
#else
#define START_EXTERN_C
#define END_EXTERN_C
#define EXTERN_C extern
#endif
#if defined(PERL_GCC_PEDANTIC)
#ifndef PERL_GCC_BRACE_GROUPS_FORBIDDEN
#define PERL_GCC_BRACE_GROUPS_FORBIDDEN
#endif
#endif
#if defined(__GNUC__) && !defined(PERL_GCC_BRACE_GROUPS_FORBIDDEN) && !defined(__cplusplus)
#ifndef PERL_USE_GCC_BRACE_GROUPS
#define PERL_USE_GCC_BRACE_GROUPS
#endif
#endif
#undef STMT_START
#undef STMT_END
#ifdef PERL_USE_GCC_BRACE_GROUPS
#define STMT_START (void)(
#define STMT_END )
#else
#if defined(VOIDFLAGS) && (VOIDFLAGS) && (defined(sun) || defined(__sun__)) && !defined(__GNUC__)
#define STMT_START if (1)
#define STMT_END else (void)0
#else
#define STMT_START do
#define STMT_END while (0)
#endif
#endif
#ifndef boolSV
#define boolSV(b) ((b) ? &PL_sv_yes : &PL_sv_no)
#endif
#ifndef DEFSV
#define DEFSV GvSV(PL_defgv)
#endif
#ifndef SAVE_DEFSV
#define SAVE_DEFSV SAVESPTR(GvSV(PL_defgv))
#endif
#ifndef AvFILLp
#define AvFILLp AvFILL
#endif
#ifndef ERRSV
#define ERRSV get_sv("@",FALSE)
#endif
#ifndef newSVpvn
#define newSVpvn(data,len) ((data) \
? ((len) ? newSVpv((data), (len)) : newSVpv("", 0)) \
: newSV(0))
#endif
#ifndef gv_stashpvn
#define gv_stashpvn(str,len,create) gv_stashpv(str,create)
#endif
#ifndef get_cv
#define get_cv perl_get_cv
#endif
#ifndef get_sv
#define get_sv perl_get_sv
#endif
#ifndef get_av
#define get_av perl_get_av
#endif
#ifndef get_hv
#define get_hv perl_get_hv
#endif
#ifndef dUNDERBAR
#define dUNDERBAR dNOOP
#endif
#ifndef UNDERBAR
#define UNDERBAR DEFSV
#endif
#ifndef dAX
#define dAX I32 ax = MARK - PL_stack_base + 1
#endif
#ifndef dITEMS
#define dITEMS I32 items = SP - MARK
#endif
#ifndef dXSTARG
#define dXSTARG SV * targ = sv_newmortal()
#endif
#ifndef dAXMARK
#define dAXMARK I32 ax = POPMARK; \
register SV ** const mark = PL_stack_base + ax++
#endif
#ifndef XSprePUSH
#define XSprePUSH (sp = PL_stack_base + ax - 1)
#endif
#if (PERL_BCDVERSION < 0x5005000)
#undef XSRETURN
#define XSRETURN(off) \
STMT_START { \
PL_stack_sp = PL_stack_base + ax + ((off) - 1); \
return; \
} STMT_END
#endif
#ifndef PERL_ABS
#define PERL_ABS(x) ((x) < 0 ? -(x) : (x))
#endif
#ifndef dVAR
#define dVAR dNOOP
#endif
#ifndef SVf
#define SVf "_"
#endif
#ifndef UTF8_MAXBYTES
#define UTF8_MAXBYTES UTF8_MAXLEN
#endif
#ifndef PERL_HASH
#define PERL_HASH(hash,str,len) \
STMT_START { \
const char *s_PeRlHaSh = str; \
I32 i_PeRlHaSh = len; \
U32 hash_PeRlHaSh = 0; \
while (i_PeRlHaSh--) \
hash_PeRlHaSh = hash_PeRlHaSh * 33 + *s_PeRlHaSh++; \
(hash) = hash_PeRlHaSh; \
} STMT_END
#endif
#ifndef PERL_SIGNALS_UNSAFE_FLAG
#define PERL_SIGNALS_UNSAFE_FLAG 0x0001
#if (PERL_BCDVERSION < 0x5008000)
#define D_PPP_PERL_SIGNALS_INIT PERL_SIGNALS_UNSAFE_FLAG
#else
#define D_PPP_PERL_SIGNALS_INIT 0
#endif
#if defined(NEED_PL_signals)
static U32 DPPP_(my_PL_signals) = D_PPP_PERL_SIGNALS_INIT;
#elif defined(NEED_PL_signals_GLOBAL)
U32 DPPP_(my_PL_signals) = D_PPP_PERL_SIGNALS_INIT;
#else
extern U32 DPPP_(my_PL_signals);
#endif
#define PL_signals DPPP_(my_PL_signals)
#endif
#if (PERL_BCDVERSION <= 0x5005004)
#define PL_ppaddr ppaddr
#define PL_no_modify no_modify
#endif
#if (PERL_BCDVERSION <= 0x5004005)
#define PL_DBsignal DBsignal
#define PL_DBsingle DBsingle
#define PL_DBsub DBsub
#define PL_DBtrace DBtrace
#define PL_Sv Sv
#define PL_compiling compiling
#define PL_copline copline
#define PL_curcop curcop
#define PL_curstash curstash
#define PL_debstash debstash
#define PL_defgv defgv
#define PL_diehook diehook
#define PL_dirty dirty
#define PL_dowarn dowarn
#define PL_errgv errgv
#define PL_expect expect
#define PL_hexdigit hexdigit
#define PL_hints hints
#define PL_laststatval laststatval
#define PL_na na
#define PL_perl_destruct_level perl_destruct_level
#define PL_perldb perldb
#define PL_rsfp_filters rsfp_filters
#define PL_rsfp rsfp
#define PL_stack_base stack_base
#define PL_stack_sp stack_sp
#define PL_statcache statcache
#define PL_stdingv stdingv
#define PL_sv_arenaroot sv_arenaroot
#define PL_sv_no sv_no
#define PL_sv_undef sv_undef
#define PL_sv_yes sv_yes
#define PL_tainted tainted
#define PL_tainting tainting
#endif
#if (PERL_BCDVERSION >= 0x5009005)
#define PL_expect (PL_parser ? PL_parser->expect : 0)
#define PL_copline (PL_parser ? PL_parser->copline : 0)
#define PL_rsfp (PL_parser ? PL_parser->rsfp : (PerlIO *) 0)
#define PL_rsfp_filters (PL_parser ? PL_parser->rsfp_filters : (AV *) 0)
#endif
#ifndef dTHR
#define dTHR dNOOP
#endif
#ifndef dTHX
#define dTHX dNOOP
#endif
#ifndef dTHXa
#define dTHXa(x) dNOOP
#endif
#ifndef pTHX
#define pTHX void
#endif
#ifndef pTHX_
#define pTHX_
#endif
#ifndef aTHX
#define aTHX
#endif
#ifndef aTHX_
#define aTHX_
#endif
#if (PERL_BCDVERSION < 0x5006000)
#ifdef USE_THREADS
#define aTHXR thr
#define aTHXR_ thr,
#else
#define aTHXR
#define aTHXR_
#endif
#define dTHXR dTHR
#else
#define aTHXR aTHX
#define aTHXR_ aTHX_
#define dTHXR dTHX
#endif
#ifndef dTHXoa
#define dTHXoa(x) dTHXa(x)
#endif
#ifndef PUSHmortal
#define PUSHmortal PUSHs(sv_newmortal())
#endif
#ifndef mPUSHp
#define mPUSHp(p,l) sv_setpvn_mg(PUSHmortal, (p), (l))
#endif
#ifndef mPUSHn
#define mPUSHn(n) sv_setnv_mg(PUSHmortal, (NV)(n))
#endif
#ifndef mPUSHi
#define mPUSHi(i) sv_setiv_mg(PUSHmortal, (IV)(i))
#endif
#ifndef mPUSHu
#define mPUSHu(u) sv_setuv_mg(PUSHmortal, (UV)(u))
#endif
#ifndef XPUSHmortal
#define XPUSHmortal XPUSHs(sv_newmortal())
#endif
#ifndef mXPUSHp
#define mXPUSHp(p,l) STMT_START { EXTEND(sp,1); sv_setpvn_mg(PUSHmortal, (p), (l)); } STMT_END
#endif
#ifndef mXPUSHn
#define mXPUSHn(n) STMT_START { EXTEND(sp,1); sv_setnv_mg(PUSHmortal, (NV)(n)); } STMT_END
#endif
#ifndef mXPUSHi
#define mXPUSHi(i) STMT_START { EXTEND(sp,1); sv_setiv_mg(PUSHmortal, (IV)(i)); } STMT_END
#endif
#ifndef mXPUSHu
#define mXPUSHu(u) STMT_START { EXTEND(sp,1); sv_setuv_mg(PUSHmortal, (UV)(u)); } STMT_END
#endif
#ifndef call_sv
#define call_sv perl_call_sv
#endif
#ifndef call_pv
#define call_pv perl_call_pv
#endif
#ifndef call_argv
#define call_argv perl_call_argv
#endif
#ifndef call_method
#define call_method perl_call_method
#endif
#ifndef eval_sv
#define eval_sv perl_eval_sv
#endif
#ifndef PERL_LOADMOD_DENY
#define PERL_LOADMOD_DENY 0x1
#endif
#ifndef PERL_LOADMOD_NOIMPORT
#define PERL_LOADMOD_NOIMPORT 0x2
#endif
#ifndef PERL_LOADMOD_IMPORT_OPS
#define PERL_LOADMOD_IMPORT_OPS 0x4
#endif
#ifndef eval_pv
#if defined(NEED_eval_pv)
static SV* DPPP_(my_eval_pv)(char *p, I32 croak_on_error);
static
#else
extern SV* DPPP_(my_eval_pv)(char *p, I32 croak_on_error);
#endif
#ifdef eval_pv
#undef eval_pv
#endif
#define eval_pv(a,b) DPPP_(my_eval_pv)(aTHX_ a,b)
#define Perl_eval_pv DPPP_(my_eval_pv)
#if defined(NEED_eval_pv) || defined(NEED_eval_pv_GLOBAL)
SV*
DPPP_(my_eval_pv)(char *p, I32 croak_on_error)
{
dSP;
SV* sv = newSVpv(p, 0);
PUSHMARK(sp);
eval_sv(sv, G_SCALAR);
SvREFCNT_dec(sv);
SPAGAIN;
sv = POPs;
PUTBACK;
if (croak_on_error && SvTRUE(GvSV(errgv)))
croak(SvPVx(GvSV(errgv), na));
return sv;
}
#endif
#endif
#ifndef vload_module
#if defined(NEED_vload_module)
static void DPPP_(my_vload_module)(U32 flags, SV *name, SV *ver, va_list *args);
static
#else
extern void DPPP_(my_vload_module)(U32 flags, SV *name, SV *ver, va_list *args);
#endif
#ifdef vload_module
#undef vload_module
#endif
#define vload_module(a,b,c,d) DPPP_(my_vload_module)(aTHX_ a,b,c,d)
#define Perl_vload_module DPPP_(my_vload_module)
#if defined(NEED_vload_module) || defined(NEED_vload_module_GLOBAL)
void
DPPP_(my_vload_module)(U32 flags, SV *name, SV *ver, va_list *args)
{
dTHR;
dVAR;
OP *veop, *imop;
OP * const modname = newSVOP(OP_CONST, 0, name);
SvREADONLY_off(((SVOP*)modname)->op_sv);
modname->op_private |= OPpCONST_BARE;
if (ver) {
veop = newSVOP(OP_CONST, 0, ver);
}
else
veop = NULL;
if (flags & PERL_LOADMOD_NOIMPORT) {
imop = sawparens(newNULLLIST());
}
else if (flags & PERL_LOADMOD_IMPORT_OPS) {
imop = va_arg(*args, OP*);
}
else {
SV *sv;
imop = NULL;
sv = va_arg(*args, SV*);
while (sv) {
imop = append_elem(OP_LIST, imop, newSVOP(OP_CONST, 0, sv));
sv = va_arg(*args, SV*);
}
}
{
const line_t ocopline = PL_copline;
COP * const ocurcop = PL_curcop;
const int oexpect = PL_expect;
#if (PERL_BCDVERSION >= 0x5004000)
utilize(!(flags & PERL_LOADMOD_DENY), start_subparse(FALSE, 0),
veop, modname, imop);
#else
utilize(!(flags & PERL_LOADMOD_DENY), start_subparse(),
modname, imop);
#endif
PL_expect = oexpect;
PL_copline = ocopline;
PL_curcop = ocurcop;
}
}
#endif
#endif
#ifndef load_module
#if defined(NEED_load_module)
static void DPPP_(my_load_module)(U32 flags, SV *name, SV *ver, ...);
static
#else
extern void DPPP_(my_load_module)(U32 flags, SV *name, SV *ver, ...);
#endif
#ifdef load_module
#undef load_module
#endif
#define load_module DPPP_(my_load_module)
#define Perl_load_module DPPP_(my_load_module)
#if defined(NEED_load_module) || defined(NEED_load_module_GLOBAL)
void
DPPP_(my_load_module)(U32 flags, SV *name, SV *ver, ...)
{
va_list args;
va_start(args, ver);
vload_module(flags, name, ver, &args);
va_end(args);
}
#endif
#endif
#ifndef newRV_inc
#define newRV_inc(sv) newRV(sv)
#endif
#ifndef newRV_noinc
#if defined(NEED_newRV_noinc)
static SV * DPPP_(my_newRV_noinc)(SV *sv);
static
#else
extern SV * DPPP_(my_newRV_noinc)(SV *sv);
#endif
#ifdef newRV_noinc
#undef newRV_noinc
#endif
#define newRV_noinc(a) DPPP_(my_newRV_noinc)(aTHX_ a)
#define Perl_newRV_noinc DPPP_(my_newRV_noinc)
#if defined(NEED_newRV_noinc) || defined(NEED_newRV_noinc_GLOBAL)
SV *
DPPP_(my_newRV_noinc)(SV *sv)
{
SV *rv = (SV *)newRV(sv);
SvREFCNT_dec(sv);
return rv;
}
#endif
#endif
#if (PERL_BCDVERSION < 0x5004063) && (PERL_BCDVERSION != 0x5004005)
#if defined(NEED_newCONSTSUB)
static void DPPP_(my_newCONSTSUB)(HV *stash, char *name, SV *sv);
static
#else
extern void DPPP_(my_newCONSTSUB)(HV *stash, char *name, SV *sv);
#endif
#ifdef newCONSTSUB
#undef newCONSTSUB
#endif
#define newCONSTSUB(a,b,c) DPPP_(my_newCONSTSUB)(aTHX_ a,b,c)
#define Perl_newCONSTSUB DPPP_(my_newCONSTSUB)
#if defined(NEED_newCONSTSUB) || defined(NEED_newCONSTSUB_GLOBAL)
void
DPPP_(my_newCONSTSUB)(HV *stash, char *name, SV *sv)
{
U32 oldhints = PL_hints;
HV *old_cop_stash = PL_curcop->cop_stash;
HV *old_curstash = PL_curstash;
line_t oldline = PL_curcop->cop_line;
PL_curcop->cop_line = PL_copline;
PL_hints &= ~HINT_BLOCK_SCOPE;
if (stash)
PL_curstash = PL_curcop->cop_stash = stash;
newSUB(
#if (PERL_BCDVERSION < 0x5003022)
start_subparse(),
#elif (PERL_BCDVERSION == 0x5003022)
start_subparse(0),
#else
start_subparse(FALSE, 0),
#endif
newSVOP(OP_CONST, 0, newSVpv(name,0)),
newSVOP(OP_CONST, 0, &PL_sv_no),
newSTATEOP(0, Nullch, newSVOP(OP_CONST, 0, sv))
);
PL_hints = oldhints;
PL_curcop->cop_stash = old_cop_stash;
PL_curstash = old_curstash;
PL_curcop->cop_line = oldline;
}
#endif
#endif
#if defined(MULTIPLICITY) || defined(PERL_OBJECT) || \
defined(PERL_CAPI) || defined(PERL_IMPLICIT_CONTEXT)
#ifndef START_MY_CXT
#define START_MY_CXT
#if (PERL_BCDVERSION < 0x5004068)
#define dMY_CXT_SV \
SV *my_cxt_sv = get_sv(MY_CXT_KEY, FALSE)
#else
#define dMY_CXT_SV \
SV *my_cxt_sv = *hv_fetch(PL_modglobal, MY_CXT_KEY, \
sizeof(MY_CXT_KEY)-1, TRUE)
#endif
#define dMY_CXT \
dMY_CXT_SV; \
my_cxt_t *my_cxtp = INT2PTR(my_cxt_t*,SvUV(my_cxt_sv))
#define MY_CXT_INIT \
dMY_CXT_SV; \
\
my_cxt_t *my_cxtp = (my_cxt_t*)SvPVX(newSV(sizeof(my_cxt_t)-1));\
Zero(my_cxtp, 1, my_cxt_t); \
sv_setuv(my_cxt_sv, PTR2UV(my_cxtp))
#define MY_CXT (*my_cxtp)
#define pMY_CXT my_cxt_t *my_cxtp
#define pMY_CXT_ pMY_CXT,
#define _pMY_CXT ,pMY_CXT
#define aMY_CXT my_cxtp
#define aMY_CXT_ aMY_CXT,
#define _aMY_CXT ,aMY_CXT
#endif
#ifndef MY_CXT_CLONE
#define MY_CXT_CLONE \
dMY_CXT_SV; \
my_cxt_t *my_cxtp = (my_cxt_t*)SvPVX(newSV(sizeof(my_cxt_t)-1));\
Copy(INT2PTR(my_cxt_t*, SvUV(my_cxt_sv)), my_cxtp, 1, my_cxt_t);\
sv_setuv(my_cxt_sv, PTR2UV(my_cxtp))
#endif
#else
#ifndef START_MY_CXT
#define START_MY_CXT static my_cxt_t my_cxt;
#define dMY_CXT_SV dNOOP
#define dMY_CXT dNOOP
#define MY_CXT_INIT NOOP
#define MY_CXT my_cxt
#define pMY_CXT void
#define pMY_CXT_
#define _pMY_CXT
#define aMY_CXT
#define aMY_CXT_
#define _aMY_CXT
#endif
#ifndef MY_CXT_CLONE
#define MY_CXT_CLONE NOOP
#endif
#endif
#ifndef IVdf
#if IVSIZE == LONGSIZE
#define IVdf "ld"
#define UVuf "lu"
#define UVof "lo"
#define UVxf "lx"
#define UVXf "lX"
#else
#if IVSIZE == INTSIZE
#define IVdf "d"
#define UVuf "u"
#define UVof "o"
#define UVxf "x"
#define UVXf "X"
#endif
#endif
#endif
#ifndef NVef
#if defined(USE_LONG_DOUBLE) && defined(HAS_LONG_DOUBLE) && \
defined(PERL_PRIfldbl)
#define NVef PERL_PRIeldbl
#define NVff PERL_PRIfldbl
#define NVgf PERL_PRIgldbl
#else
#define NVef "e"
#define NVff "f"
#define NVgf "g"
#endif
#endif
#ifndef SvREFCNT_inc
#ifdef PERL_USE_GCC_BRACE_GROUPS
#define SvREFCNT_inc(sv) \
({ \
SV * const _sv = (SV*)(sv); \
if (_sv) \
(SvREFCNT(_sv))++; \
_sv; \
})
#else
#define SvREFCNT_inc(sv) \
((PL_Sv=(SV*)(sv)) ? (++(SvREFCNT(PL_Sv)),PL_Sv) : NULL)
#endif
#endif
#ifndef SvREFCNT_inc_simple
#ifdef PERL_USE_GCC_BRACE_GROUPS
#define SvREFCNT_inc_simple(sv) \
({ \
if (sv) \
(SvREFCNT(sv))++; \
(SV *)(sv); \
})
#else
#define SvREFCNT_inc_simple(sv) \
((sv) ? (SvREFCNT(sv)++,(SV*)(sv)) : NULL)
#endif
#endif
#ifndef SvREFCNT_inc_NN
#ifdef PERL_USE_GCC_BRACE_GROUPS
#define SvREFCNT_inc_NN(sv) \
({ \
SV * const _sv = (SV*)(sv); \
SvREFCNT(_sv)++; \
_sv; \
})
#else
#define SvREFCNT_inc_NN(sv) \
(PL_Sv=(SV*)(sv),++(SvREFCNT(PL_Sv)),PL_Sv)
#endif
#endif
#ifndef SvREFCNT_inc_void
#ifdef PERL_USE_GCC_BRACE_GROUPS
#define SvREFCNT_inc_void(sv) \
({ \
SV * const _sv = (SV*)(sv); \
if (_sv) \
(void)(SvREFCNT(_sv)++); \
})
#else
#define SvREFCNT_inc_void(sv) \
(void)((PL_Sv=(SV*)(sv)) ? ++(SvREFCNT(PL_Sv)) : 0)
#endif
#endif
#ifndef SvREFCNT_inc_simple_void
#define SvREFCNT_inc_simple_void(sv) STMT_START { if (sv) SvREFCNT(sv)++; } STMT_END
#endif
#ifndef SvREFCNT_inc_simple_NN
#define SvREFCNT_inc_simple_NN(sv) (++SvREFCNT(sv), (SV*)(sv))
#endif
#ifndef SvREFCNT_inc_void_NN
#define SvREFCNT_inc_void_NN(sv) (void)(++SvREFCNT((SV*)(sv)))
#endif
#ifndef SvREFCNT_inc_simple_void_NN
#define SvREFCNT_inc_simple_void_NN(sv) (void)(++SvREFCNT((SV*)(sv)))
#endif
#if !defined(NEED_sv_2pv_flags) && defined(NEED_sv_2pv_nolen)
#define NEED_sv_2pv_flags
#endif
#if !defined(NEED_sv_2pv_flags_GLOBAL) && defined(NEED_sv_2pv_nolen_GLOBAL)
#define NEED_sv_2pv_flags_GLOBAL
#endif
#ifndef sv_2pv_nolen
#define sv_2pv_nolen(sv) SvPV_nolen(sv)
#endif
#ifdef SvPVbyte
#if (PERL_BCDVERSION < 0x5007000)
#if defined(NEED_sv_2pvbyte)
static char * DPPP_(my_sv_2pvbyte)(pTHX_ register SV *sv, STRLEN *lp);
static
#else
extern char * DPPP_(my_sv_2pvbyte)(pTHX_ register SV *sv, STRLEN *lp);
#endif
#ifdef sv_2pvbyte
#undef sv_2pvbyte
#endif
#define sv_2pvbyte(a,b) DPPP_(my_sv_2pvbyte)(aTHX_ a,b)
#define Perl_sv_2pvbyte DPPP_(my_sv_2pvbyte)
#if defined(NEED_sv_2pvbyte) || defined(NEED_sv_2pvbyte_GLOBAL)
char *
DPPP_(my_sv_2pvbyte)(pTHX_ register SV *sv, STRLEN *lp)
{
sv_utf8_downgrade(sv,0);
return SvPV(sv,*lp);
}
#endif
#undef SvPVbyte
#define SvPVbyte(sv, lp) \
((SvFLAGS(sv) & (SVf_POK|SVf_UTF8)) == (SVf_POK) \
? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_2pvbyte(sv, &lp))
#endif
#else
#define SvPVbyte SvPV
#define sv_2pvbyte sv_2pv
#endif
#ifndef sv_2pvbyte_nolen
#define sv_2pvbyte_nolen(sv) sv_2pv_nolen(sv)
#endif
#ifndef SV_IMMEDIATE_UNREF
#define SV_IMMEDIATE_UNREF 0
#endif
#ifndef SV_GMAGIC
#define SV_GMAGIC 0
#endif
#ifndef SV_COW_DROP_PV
#define SV_COW_DROP_PV 0
#endif
#ifndef SV_UTF8_NO_ENCODING
#define SV_UTF8_NO_ENCODING 0
#endif
#ifndef SV_NOSTEAL
#define SV_NOSTEAL 0
#endif
#ifndef SV_CONST_RETURN
#define SV_CONST_RETURN 0
#endif
#ifndef SV_MUTABLE_RETURN
#define SV_MUTABLE_RETURN 0
#endif
#ifndef SV_SMAGIC
#define SV_SMAGIC 0
#endif
#ifndef SV_HAS_TRAILING_NUL
#define SV_HAS_TRAILING_NUL 0
#endif
#ifndef SV_COW_SHARED_HASH_KEYS
#define SV_COW_SHARED_HASH_KEYS 0
#endif
#if (PERL_BCDVERSION < 0x5007002)
#if defined(NEED_sv_2pv_flags)
static char * DPPP_(my_sv_2pv_flags)(pTHX_ SV * sv, STRLEN * lp, I32 flags);
static
#else
extern char * DPPP_(my_sv_2pv_flags)(pTHX_ SV * sv, STRLEN * lp, I32 flags);
#endif
#ifdef sv_2pv_flags
#undef sv_2pv_flags
#endif
#define sv_2pv_flags(a,b,c) DPPP_(my_sv_2pv_flags)(aTHX_ a,b,c)
#define Perl_sv_2pv_flags DPPP_(my_sv_2pv_flags)
#if defined(NEED_sv_2pv_flags) || defined(NEED_sv_2pv_flags_GLOBAL)
char *
DPPP_(my_sv_2pv_flags)(pTHX_ SV *sv, STRLEN *lp, I32 flags)
{
STRLEN n_a = (STRLEN) flags;
return sv_2pv(sv, lp ? lp : &n_a);
}
#endif
#if defined(NEED_sv_pvn_force_flags)
static char * DPPP_(my_sv_pvn_force_flags)(pTHX_ SV * sv, STRLEN * lp, I32 flags);
static
#else
extern char * DPPP_(my_sv_pvn_force_flags)(pTHX_ SV * sv, STRLEN * lp, I32 flags);
#endif
#ifdef sv_pvn_force_flags
#undef sv_pvn_force_flags
#endif
#define sv_pvn_force_flags(a,b,c) DPPP_(my_sv_pvn_force_flags)(aTHX_ a,b,c)
#define Perl_sv_pvn_force_flags DPPP_(my_sv_pvn_force_flags)
#if defined(NEED_sv_pvn_force_flags) || defined(NEED_sv_pvn_force_flags_GLOBAL)
char *
DPPP_(my_sv_pvn_force_flags)(pTHX_ SV *sv, STRLEN *lp, I32 flags)
{
STRLEN n_a = (STRLEN) flags;
return sv_pvn_force(sv, lp ? lp : &n_a);
}
#endif
#endif
#ifndef SvPV_const
#define SvPV_const(sv, lp) SvPV_flags_const(sv, lp, SV_GMAGIC)
#endif
#ifndef SvPV_mutable
#define SvPV_mutable(sv, lp) SvPV_flags_mutable(sv, lp, SV_GMAGIC)
#endif
#ifndef SvPV_flags
#define SvPV_flags(sv, lp, flags) \
((SvFLAGS(sv) & (SVf_POK)) == SVf_POK \
? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_2pv_flags(sv, &lp, flags))
#endif
#ifndef SvPV_flags_const
#define SvPV_flags_const(sv, lp, flags) \
((SvFLAGS(sv) & (SVf_POK)) == SVf_POK \
? ((lp = SvCUR(sv)), SvPVX_const(sv)) : \
(const char*) sv_2pv_flags(sv, &lp, flags|SV_CONST_RETURN))
#endif
#ifndef SvPV_flags_const_nolen
#define SvPV_flags_const_nolen(sv, flags) \
((SvFLAGS(sv) & (SVf_POK)) == SVf_POK \
? SvPVX_const(sv) : \
(const char*) sv_2pv_flags(sv, 0, flags|SV_CONST_RETURN))
#endif
#ifndef SvPV_flags_mutable
#define SvPV_flags_mutable(sv, lp, flags) \
((SvFLAGS(sv) & (SVf_POK)) == SVf_POK \
? ((lp = SvCUR(sv)), SvPVX_mutable(sv)) : \
sv_2pv_flags(sv, &lp, flags|SV_MUTABLE_RETURN))
#endif
#ifndef SvPV_force
#define SvPV_force(sv, lp) SvPV_force_flags(sv, lp, SV_GMAGIC)
#endif
#ifndef SvPV_force_nolen
#define SvPV_force_nolen(sv) SvPV_force_flags_nolen(sv, SV_GMAGIC)
#endif
#ifndef SvPV_force_mutable
#define SvPV_force_mutable(sv, lp) SvPV_force_flags_mutable(sv, lp, SV_GMAGIC)
#endif
#ifndef SvPV_force_nomg
#define SvPV_force_nomg(sv, lp) SvPV_force_flags(sv, lp, 0)
#endif
#ifndef SvPV_force_nomg_nolen
#define SvPV_force_nomg_nolen(sv) SvPV_force_flags_nolen(sv, 0)
#endif
#ifndef SvPV_force_flags
#define SvPV_force_flags(sv, lp, flags) \
((SvFLAGS(sv) & (SVf_POK|SVf_THINKFIRST)) == SVf_POK \
? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_pvn_force_flags(sv, &lp, flags))
#endif
#ifndef SvPV_force_flags_nolen
#define SvPV_force_flags_nolen(sv, flags) \
((SvFLAGS(sv) & (SVf_POK|SVf_THINKFIRST)) == SVf_POK \
? SvPVX(sv) : sv_pvn_force_flags(sv, 0, flags))
#endif
#ifndef SvPV_force_flags_mutable
#define SvPV_force_flags_mutable(sv, lp, flags) \
((SvFLAGS(sv) & (SVf_POK|SVf_THINKFIRST)) == SVf_POK \
? ((lp = SvCUR(sv)), SvPVX_mutable(sv)) \
: sv_pvn_force_flags(sv, &lp, flags|SV_MUTABLE_RETURN))
#endif
#ifndef SvPV_nolen
#define SvPV_nolen(sv) \
((SvFLAGS(sv) & (SVf_POK)) == SVf_POK \
? SvPVX(sv) : sv_2pv_flags(sv, 0, SV_GMAGIC))
#endif
#ifndef SvPV_nolen_const
#define SvPV_nolen_const(sv) \
((SvFLAGS(sv) & (SVf_POK)) == SVf_POK \
? SvPVX_const(sv) : sv_2pv_flags(sv, 0, SV_GMAGIC|SV_CONST_RETURN))
#endif
#ifndef SvPV_nomg
#define SvPV_nomg(sv, lp) SvPV_flags(sv, lp, 0)
#endif
#ifndef SvPV_nomg_const
#define SvPV_nomg_const(sv, lp) SvPV_flags_const(sv, lp, 0)
#endif
#ifndef SvPV_nomg_const_nolen
#define SvPV_nomg_const_nolen(sv) SvPV_flags_const_nolen(sv, 0)
#endif
#ifndef SvMAGIC_set
#define SvMAGIC_set(sv, val) \
STMT_START { assert(SvTYPE(sv) >= SVt_PVMG); \
(((XPVMG*) SvANY(sv))->xmg_magic = (val)); } STMT_END
#endif
#if (PERL_BCDVERSION < 0x5009003)
#ifndef SvPVX_const
#define SvPVX_const(sv) ((const char*) (0 + SvPVX(sv)))
#endif
#ifndef SvPVX_mutable
#define SvPVX_mutable(sv) (0 + SvPVX(sv))
#endif
#ifndef SvRV_set
#define SvRV_set(sv, val) \
STMT_START { assert(SvTYPE(sv) >= SVt_RV); \
(((XRV*) SvANY(sv))->xrv_rv = (val)); } STMT_END
#endif
#else
#ifndef SvPVX_const
#define SvPVX_const(sv) ((const char*)((sv)->sv_u.svu_pv))
#endif
#ifndef SvPVX_mutable
#define SvPVX_mutable(sv) ((sv)->sv_u.svu_pv)
#endif
#ifndef SvRV_set
#define SvRV_set(sv, val) \
STMT_START { assert(SvTYPE(sv) >= SVt_RV); \
((sv)->sv_u.svu_rv = (val)); } STMT_END
#endif
#endif
#ifndef SvSTASH_set
#define SvSTASH_set(sv, val) \
STMT_START { assert(SvTYPE(sv) >= SVt_PVMG); \
(((XPVMG*) SvANY(sv))->xmg_stash = (val)); } STMT_END
#endif
#if (PERL_BCDVERSION < 0x5004000)
#ifndef SvUV_set
#define SvUV_set(sv, val) \
STMT_START { assert(SvTYPE(sv) == SVt_IV || SvTYPE(sv) >= SVt_PVIV); \
(((XPVIV*) SvANY(sv))->xiv_iv = (IV) (val)); } STMT_END
#endif
#else
#ifndef SvUV_set
#define SvUV_set(sv, val) \
STMT_START { assert(SvTYPE(sv) == SVt_IV || SvTYPE(sv) >= SVt_PVIV); \
(((XPVUV*) SvANY(sv))->xuv_uv = (val)); } STMT_END
#endif
#endif
#if (PERL_BCDVERSION >= 0x5004000) && !defined(vnewSVpvf)
#if defined(NEED_vnewSVpvf)
static SV * DPPP_(my_vnewSVpvf)(pTHX_ const char * pat, va_list * args);
static
#else
extern SV * DPPP_(my_vnewSVpvf)(pTHX_ const char * pat, va_list * args);
#endif
#ifdef vnewSVpvf
#undef vnewSVpvf
#endif
#define vnewSVpvf(a,b) DPPP_(my_vnewSVpvf)(aTHX_ a,b)
#define Perl_vnewSVpvf DPPP_(my_vnewSVpvf)
#if defined(NEED_vnewSVpvf) || defined(NEED_vnewSVpvf_GLOBAL)
SV *
DPPP_(my_vnewSVpvf)(pTHX_ const char *pat, va_list *args)
{
register SV *sv = newSV(0);
sv_vsetpvfn(sv, pat, strlen(pat), args, Null(SV**), 0, Null(bool*));
return sv;
}
#endif
#endif
#if (PERL_BCDVERSION >= 0x5004000) && !defined(sv_vcatpvf)
#define sv_vcatpvf(sv, pat, args) sv_vcatpvfn(sv, pat, strlen(pat), args, Null(SV**), 0, Null(bool*))
#endif
#if (PERL_BCDVERSION >= 0x5004000) && !defined(sv_vsetpvf)
#define sv_vsetpvf(sv, pat, args) sv_vsetpvfn(sv, pat, strlen(pat), args, Null(SV**), 0, Null(bool*))
#endif
#if (PERL_BCDVERSION >= 0x5004000) && !defined(sv_catpvf_mg)
#if defined(NEED_sv_catpvf_mg)
static void DPPP_(my_sv_catpvf_mg)(pTHX_ SV * sv, const char * pat, ...);
static
#else
extern void DPPP_(my_sv_catpvf_mg)(pTHX_ SV * sv, const char * pat, ...);
#endif
#define Perl_sv_catpvf_mg DPPP_(my_sv_catpvf_mg)
#if defined(NEED_sv_catpvf_mg) || defined(NEED_sv_catpvf_mg_GLOBAL)
void
DPPP_(my_sv_catpvf_mg)(pTHX_ SV *sv, const char *pat, ...)
{
va_list args;
va_start(args, pat);
sv_vcatpvfn(sv, pat, strlen(pat), &args, Null(SV**), 0, Null(bool*));
SvSETMAGIC(sv);
va_end(args);
}
#endif
#endif
#ifdef PERL_IMPLICIT_CONTEXT
#if (PERL_BCDVERSION >= 0x5004000) && !defined(sv_catpvf_mg_nocontext)
#if defined(NEED_sv_catpvf_mg_nocontext)
static void DPPP_(my_sv_catpvf_mg_nocontext)(SV * sv, const char * pat, ...);
static
#else
extern void DPPP_(my_sv_catpvf_mg_nocontext)(SV * sv, const char * pat, ...);
#endif
#define sv_catpvf_mg_nocontext DPPP_(my_sv_catpvf_mg_nocontext)
#define Perl_sv_catpvf_mg_nocontext DPPP_(my_sv_catpvf_mg_nocontext)
#if defined(NEED_sv_catpvf_mg_nocontext) || defined(NEED_sv_catpvf_mg_nocontext_GLOBAL)
void
DPPP_(my_sv_catpvf_mg_nocontext)(SV *sv, const char *pat, ...)
{
dTHX;
va_list args;
va_start(args, pat);
sv_vcatpvfn(sv, pat, strlen(pat), &args, Null(SV**), 0, Null(bool*));
SvSETMAGIC(sv);
va_end(args);
}
#endif
#endif
#endif
#ifndef sv_catpvf_mg
#ifdef PERL_IMPLICIT_CONTEXT
#define sv_catpvf_mg Perl_sv_catpvf_mg_nocontext
#else
#define sv_catpvf_mg Perl_sv_catpvf_mg
#endif
#endif
#if (PERL_BCDVERSION >= 0x5004000) && !defined(sv_vcatpvf_mg)
#define sv_vcatpvf_mg(sv, pat, args) \
STMT_START { \
sv_vcatpvfn(sv, pat, strlen(pat), args, Null(SV**), 0, Null(bool*)); \
SvSETMAGIC(sv); \
} STMT_END
#endif
#if (PERL_BCDVERSION >= 0x5004000) && !defined(sv_setpvf_mg)
#if defined(NEED_sv_setpvf_mg)
static void DPPP_(my_sv_setpvf_mg)(pTHX_ SV * sv, const char * pat, ...);
static
#else
extern void DPPP_(my_sv_setpvf_mg)(pTHX_ SV * sv, const char * pat, ...);
#endif
#define Perl_sv_setpvf_mg DPPP_(my_sv_setpvf_mg)
#if defined(NEED_sv_setpvf_mg) || defined(NEED_sv_setpvf_mg_GLOBAL)
void
DPPP_(my_sv_setpvf_mg)(pTHX_ SV *sv, const char *pat, ...)
{
va_list args;
va_start(args, pat);
sv_vsetpvfn(sv, pat, strlen(pat), &args, Null(SV**), 0, Null(bool*));
SvSETMAGIC(sv);
va_end(args);
}
#endif
#endif
#ifdef PERL_IMPLICIT_CONTEXT
#if (PERL_BCDVERSION >= 0x5004000) && !defined(sv_setpvf_mg_nocontext)
#if defined(NEED_sv_setpvf_mg_nocontext)
static void DPPP_(my_sv_setpvf_mg_nocontext)(SV * sv, const char * pat, ...);
static
#else
extern void DPPP_(my_sv_setpvf_mg_nocontext)(SV * sv, const char * pat, ...);
#endif
#define sv_setpvf_mg_nocontext DPPP_(my_sv_setpvf_mg_nocontext)
#define Perl_sv_setpvf_mg_nocontext DPPP_(my_sv_setpvf_mg_nocontext)
#if defined(NEED_sv_setpvf_mg_nocontext) || defined(NEED_sv_setpvf_mg_nocontext_GLOBAL)
void
DPPP_(my_sv_setpvf_mg_nocontext)(SV *sv, const char *pat, ...)
{
dTHX;
va_list args;
va_start(args, pat);
sv_vsetpvfn(sv, pat, strlen(pat), &args, Null(SV**), 0, Null(bool*));
SvSETMAGIC(sv);
va_end(args);
}
#endif
#endif
#endif
#ifndef sv_setpvf_mg
#ifdef PERL_IMPLICIT_CONTEXT
#define sv_setpvf_mg Perl_sv_setpvf_mg_nocontext
#else
#define sv_setpvf_mg Perl_sv_setpvf_mg
#endif
#endif
#if (PERL_BCDVERSION >= 0x5004000) && !defined(sv_vsetpvf_mg)
#define sv_vsetpvf_mg(sv, pat, args) \
STMT_START { \
sv_vsetpvfn(sv, pat, strlen(pat), args, Null(SV**), 0, Null(bool*)); \
SvSETMAGIC(sv); \
} STMT_END
#endif
#ifndef newSVpvn_share
#if defined(NEED_newSVpvn_share)
static SV * DPPP_(my_newSVpvn_share)(pTHX_ const char *src, I32 len, U32 hash);
static
#else
extern SV * DPPP_(my_newSVpvn_share)(pTHX_ const char *src, I32 len, U32 hash);
#endif
#ifdef newSVpvn_share
#undef newSVpvn_share
#endif
#define newSVpvn_share(a,b,c) DPPP_(my_newSVpvn_share)(aTHX_ a,b,c)
#define Perl_newSVpvn_share DPPP_(my_newSVpvn_share)
#if defined(NEED_newSVpvn_share) || defined(NEED_newSVpvn_share_GLOBAL)
SV *
DPPP_(my_newSVpvn_share)(pTHX_ const char *src, I32 len, U32 hash)
{
SV *sv;
if (len < 0)
len = -len;
if (!hash)
PERL_HASH(hash, src, len);
sv = newSVpvn((char *) src, len);
sv_upgrade(sv, SVt_PVIV);
SvIVX(sv) = hash;
SvREADONLY_on(sv);
SvPOK_on(sv);
return sv;
}
#endif
#endif
#ifndef SvSHARED_HASH
#define SvSHARED_HASH(sv) (0 + SvUVX(sv))
#endif
#ifndef WARN_ALL
#define WARN_ALL 0
#endif
#ifndef WARN_CLOSURE
#define WARN_CLOSURE 1
#endif
#ifndef WARN_DEPRECATED
#define WARN_DEPRECATED 2
#endif
#ifndef WARN_EXITING
#define WARN_EXITING 3
#endif
#ifndef WARN_GLOB
#define WARN_GLOB 4
#endif
#ifndef WARN_IO
#define WARN_IO 5
#endif
#ifndef WARN_CLOSED
#define WARN_CLOSED 6
#endif
#ifndef WARN_EXEC
#define WARN_EXEC 7
#endif
#ifndef WARN_LAYER
#define WARN_LAYER 8
#endif
#ifndef WARN_NEWLINE
#define WARN_NEWLINE 9
#endif
#ifndef WARN_PIPE
#define WARN_PIPE 10
#endif
#ifndef WARN_UNOPENED
#define WARN_UNOPENED 11
#endif
#ifndef WARN_MISC
#define WARN_MISC 12
#endif
#ifndef WARN_NUMERIC
#define WARN_NUMERIC 13
#endif
#ifndef WARN_ONCE
#define WARN_ONCE 14
#endif
#ifndef WARN_OVERFLOW
#define WARN_OVERFLOW 15
#endif
#ifndef WARN_PACK
#define WARN_PACK 16
#endif
#ifndef WARN_PORTABLE
#define WARN_PORTABLE 17
#endif
#ifndef WARN_RECURSION
#define WARN_RECURSION 18
#endif
#ifndef WARN_REDEFINE
#define WARN_REDEFINE 19
#endif
#ifndef WARN_REGEXP
#define WARN_REGEXP 20
#endif
#ifndef WARN_SEVERE
#define WARN_SEVERE 21
#endif
#ifndef WARN_DEBUGGING
#define WARN_DEBUGGING 22
#endif
#ifndef WARN_INPLACE
#define WARN_INPLACE 23
#endif
#ifndef WARN_INTERNAL
#define WARN_INTERNAL 24
#endif
#ifndef WARN_MALLOC
#define WARN_MALLOC 25
#endif
#ifndef WARN_SIGNAL
#define WARN_SIGNAL 26
#endif
#ifndef WARN_SUBSTR
#define WARN_SUBSTR 27
#endif
#ifndef WARN_SYNTAX
#define WARN_SYNTAX 28
#endif
#ifndef WARN_AMBIGUOUS
#define WARN_AMBIGUOUS 29
#endif
#ifndef WARN_BAREWORD
#define WARN_BAREWORD 30
#endif
#ifndef WARN_DIGIT
#define WARN_DIGIT 31
#endif
#ifndef WARN_PARENTHESIS
#define WARN_PARENTHESIS 32
#endif
#ifndef WARN_PRECEDENCE
#define WARN_PRECEDENCE 33
#endif
#ifndef WARN_PRINTF
#define WARN_PRINTF 34
#endif
#ifndef WARN_PROTOTYPE
#define WARN_PROTOTYPE 35
#endif
#ifndef WARN_QW
#define WARN_QW 36
#endif
#ifndef WARN_RESERVED
#define WARN_RESERVED 37
#endif
#ifndef WARN_SEMICOLON
#define WARN_SEMICOLON 38
#endif
#ifndef WARN_TAINT
#define WARN_TAINT 39
#endif
#ifndef WARN_THREADS
#define WARN_THREADS 40
#endif
#ifndef WARN_UNINITIALIZED
#define WARN_UNINITIALIZED 41
#endif
#ifndef WARN_UNPACK
#define WARN_UNPACK 42
#endif
#ifndef WARN_UNTIE
#define WARN_UNTIE 43
#endif
#ifndef WARN_UTF8
#define WARN_UTF8 44
#endif
#ifndef WARN_VOID
#define WARN_VOID 45
#endif
#ifndef WARN_ASSERTIONS
#define WARN_ASSERTIONS 46
#endif
#ifndef packWARN
#define packWARN(a) (a)
#endif
#ifndef ckWARN
#ifdef G_WARN_ON
#define ckWARN(a) (PL_dowarn & G_WARN_ON)
#else
#define ckWARN(a) PL_dowarn
#endif
#endif
#if (PERL_BCDVERSION >= 0x5004000) && !defined(warner)
#if defined(NEED_warner)
static void DPPP_(my_warner)(U32 err, const char *pat, ...);
static
#else
extern void DPPP_(my_warner)(U32 err, const char *pat, ...);
#endif
#define Perl_warner DPPP_(my_warner)
#if defined(NEED_warner) || defined(NEED_warner_GLOBAL)
void
DPPP_(my_warner)(U32 err, const char *pat, ...)
{
SV *sv;
va_list args;
PERL_UNUSED_ARG(err);
va_start(args, pat);
sv = vnewSVpvf(pat, &args);
va_end(args);
sv_2mortal(sv);
warn("%s", SvPV_nolen(sv));
}
#define warner Perl_warner
#define Perl_warner_nocontext Perl_warner
#endif
#endif
#ifndef STR_WITH_LEN
#define STR_WITH_LEN(s) (s ""), (sizeof(s)-1)
#endif
#ifndef newSVpvs
#define newSVpvs(str) newSVpvn(str "", sizeof(str) - 1)
#endif
#ifndef sv_catpvs
#define sv_catpvs(sv, str) sv_catpvn(sv, str "", sizeof(str) - 1)
#endif
#ifndef sv_setpvs
#define sv_setpvs(sv, str) sv_setpvn(sv, str "", sizeof(str) - 1)
#endif
#ifndef hv_fetchs
#define hv_fetchs(hv, key, lval) hv_fetch(hv, key "", sizeof(key) - 1, lval)
#endif
#ifndef hv_stores
#define hv_stores(hv, key, val) hv_store(hv, key "", sizeof(key) - 1, val, 0)
#endif
#ifndef SvGETMAGIC
#define SvGETMAGIC(x) STMT_START { if (SvGMAGICAL(x)) mg_get(x); } STMT_END
#endif
#ifndef PERL_MAGIC_sv
#define PERL_MAGIC_sv '\0'
#endif
#ifndef PERL_MAGIC_overload
#define PERL_MAGIC_overload 'A'
#endif
#ifndef PERL_MAGIC_overload_elem
#define PERL_MAGIC_overload_elem 'a'
#endif
#ifndef PERL_MAGIC_overload_table
#define PERL_MAGIC_overload_table 'c'
#endif
#ifndef PERL_MAGIC_bm
#define PERL_MAGIC_bm 'B'
#endif
#ifndef PERL_MAGIC_regdata
#define PERL_MAGIC_regdata 'D'
#endif
#ifndef PERL_MAGIC_regdatum
#define PERL_MAGIC_regdatum 'd'
#endif
#ifndef PERL_MAGIC_env
#define PERL_MAGIC_env 'E'
#endif
#ifndef PERL_MAGIC_envelem
#define PERL_MAGIC_envelem 'e'
#endif
#ifndef PERL_MAGIC_fm
#define PERL_MAGIC_fm 'f'
#endif
#ifndef PERL_MAGIC_regex_global
#define PERL_MAGIC_regex_global 'g'
#endif
#ifndef PERL_MAGIC_isa
#define PERL_MAGIC_isa 'I'
#endif
#ifndef PERL_MAGIC_isaelem
#define PERL_MAGIC_isaelem 'i'
#endif
#ifndef PERL_MAGIC_nkeys
#define PERL_MAGIC_nkeys 'k'
#endif
#ifndef PERL_MAGIC_dbfile
#define PERL_MAGIC_dbfile 'L'
#endif
#ifndef PERL_MAGIC_dbline
#define PERL_MAGIC_dbline 'l'
#endif
#ifndef PERL_MAGIC_mutex
#define PERL_MAGIC_mutex 'm'
#endif
#ifndef PERL_MAGIC_shared
#define PERL_MAGIC_shared 'N'
#endif
#ifndef PERL_MAGIC_shared_scalar
#define PERL_MAGIC_shared_scalar 'n'
#endif
#ifndef PERL_MAGIC_collxfrm
#define PERL_MAGIC_collxfrm 'o'
#endif
#ifndef PERL_MAGIC_tied
#define PERL_MAGIC_tied 'P'
#endif
#ifndef PERL_MAGIC_tiedelem
#define PERL_MAGIC_tiedelem 'p'
#endif
#ifndef PERL_MAGIC_tiedscalar
#define PERL_MAGIC_tiedscalar 'q'
#endif
#ifndef PERL_MAGIC_qr
#define PERL_MAGIC_qr 'r'
#endif
#ifndef PERL_MAGIC_sig
#define PERL_MAGIC_sig 'S'
#endif
#ifndef PERL_MAGIC_sigelem
#define PERL_MAGIC_sigelem 's'
#endif
#ifndef PERL_MAGIC_taint
#define PERL_MAGIC_taint 't'
#endif
#ifndef PERL_MAGIC_uvar
#define PERL_MAGIC_uvar 'U'
#endif
#ifndef PERL_MAGIC_uvar_elem
#define PERL_MAGIC_uvar_elem 'u'
#endif
#ifndef PERL_MAGIC_vstring
#define PERL_MAGIC_vstring 'V'
#endif
#ifndef PERL_MAGIC_vec
#define PERL_MAGIC_vec 'v'
#endif
#ifndef PERL_MAGIC_utf8
#define PERL_MAGIC_utf8 'w'
#endif
#ifndef PERL_MAGIC_substr
#define PERL_MAGIC_substr 'x'
#endif
#ifndef PERL_MAGIC_defelem
#define PERL_MAGIC_defelem 'y'
#endif
#ifndef PERL_MAGIC_glob
#define PERL_MAGIC_glob '*'
#endif
#ifndef PERL_MAGIC_arylen
#define PERL_MAGIC_arylen '#'
#endif
#ifndef PERL_MAGIC_pos
#define PERL_MAGIC_pos '.'
#endif
#ifndef PERL_MAGIC_backref
#define PERL_MAGIC_backref '<'
#endif
#ifndef PERL_MAGIC_ext
#define PERL_MAGIC_ext '~'
#endif
#ifndef sv_catpvn_nomg
#define sv_catpvn_nomg sv_catpvn
#endif
#ifndef sv_catsv_nomg
#define sv_catsv_nomg sv_catsv
#endif
#ifndef sv_setsv_nomg
#define sv_setsv_nomg sv_setsv
#endif
#ifndef sv_pvn_nomg
#define sv_pvn_nomg sv_pvn
#endif
#ifndef SvIV_nomg
#define SvIV_nomg SvIV
#endif
#ifndef SvUV_nomg
#define SvUV_nomg SvUV
#endif
#ifndef sv_catpv_mg
#define sv_catpv_mg(sv, ptr) \
STMT_START { \
SV *TeMpSv = sv; \
sv_catpv(TeMpSv,ptr); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef sv_catpvn_mg
#define sv_catpvn_mg(sv, ptr, len) \
STMT_START { \
SV *TeMpSv = sv; \
sv_catpvn(TeMpSv,ptr,len); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef sv_catsv_mg
#define sv_catsv_mg(dsv, ssv) \
STMT_START { \
SV *TeMpSv = dsv; \
sv_catsv(TeMpSv,ssv); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef sv_setiv_mg
#define sv_setiv_mg(sv, i) \
STMT_START { \
SV *TeMpSv = sv; \
sv_setiv(TeMpSv,i); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef sv_setnv_mg
#define sv_setnv_mg(sv, num) \
STMT_START { \
SV *TeMpSv = sv; \
sv_setnv(TeMpSv,num); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef sv_setpv_mg
#define sv_setpv_mg(sv, ptr) \
STMT_START { \
SV *TeMpSv = sv; \
sv_setpv(TeMpSv,ptr); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef sv_setpvn_mg
#define sv_setpvn_mg(sv, ptr, len) \
STMT_START { \
SV *TeMpSv = sv; \
sv_setpvn(TeMpSv,ptr,len); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef sv_setsv_mg
#define sv_setsv_mg(dsv, ssv) \
STMT_START { \
SV *TeMpSv = dsv; \
sv_setsv(TeMpSv,ssv); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef sv_setuv_mg
#define sv_setuv_mg(sv, i) \
STMT_START { \
SV *TeMpSv = sv; \
sv_setuv(TeMpSv,i); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef sv_usepvn_mg
#define sv_usepvn_mg(sv, ptr, len) \
STMT_START { \
SV *TeMpSv = sv; \
sv_usepvn(TeMpSv,ptr,len); \
SvSETMAGIC(TeMpSv); \
} STMT_END
#endif
#ifndef SvVSTRING_mg
#define SvVSTRING_mg(sv) (SvMAGICAL(sv) ? mg_find(sv, PERL_MAGIC_vstring) : NULL)
#endif
#if (PERL_BCDVERSION < 0x5004000)
#elif (PERL_BCDVERSION < 0x5008000)
#define sv_magic_portable(sv, obj, how, name, namlen) \
STMT_START { \
SV *SvMp_sv = (sv); \
char *SvMp_name = (char *) (name); \
I32 SvMp_namlen = (namlen); \
if (SvMp_name && SvMp_namlen == 0) \
{ \
MAGIC *mg; \
sv_magic(SvMp_sv, obj, how, 0, 0); \
mg = SvMAGIC(SvMp_sv); \
mg->mg_len = -42;  \
mg->mg_ptr = SvMp_name; \
} \
else \
{ \
sv_magic(SvMp_sv, obj, how, SvMp_name, SvMp_namlen); \
} \
} STMT_END
#else
#define sv_magic_portable(a, b, c, d, e) sv_magic(a, b, c, d, e)
#endif
#ifdef USE_ITHREADS
#ifndef CopFILE
#define CopFILE(c) ((c)->cop_file)
#endif
#ifndef CopFILEGV
#define CopFILEGV(c) (CopFILE(c) ? gv_fetchfile(CopFILE(c)) : Nullgv)
#endif
#ifndef CopFILE_set
#define CopFILE_set(c,pv) ((c)->cop_file = savepv(pv))
#endif
#ifndef CopFILESV
#define CopFILESV(c) (CopFILE(c) ? GvSV(gv_fetchfile(CopFILE(c))) : Nullsv)
#endif
#ifndef CopFILEAV
#define CopFILEAV(c) (CopFILE(c) ? GvAV(gv_fetchfile(CopFILE(c))) : Nullav)
#endif
#ifndef CopSTASHPV
#define CopSTASHPV(c) ((c)->cop_stashpv)
#endif
#ifndef CopSTASHPV_set
#define CopSTASHPV_set(c,pv) ((c)->cop_stashpv = ((pv) ? savepv(pv) : Nullch))
#endif
#ifndef CopSTASH
#define CopSTASH(c) (CopSTASHPV(c) ? gv_stashpv(CopSTASHPV(c),GV_ADD) : Nullhv)
#endif
#ifndef CopSTASH_set
#define CopSTASH_set(c,hv) CopSTASHPV_set(c, (hv) ? HvNAME(hv) : Nullch)
#endif
#ifndef CopSTASH_eq
#define CopSTASH_eq(c,hv) ((hv) && (CopSTASHPV(c) == HvNAME(hv) \
|| (CopSTASHPV(c) && HvNAME(hv) \
&& strEQ(CopSTASHPV(c), HvNAME(hv)))))
#endif
#else
#ifndef CopFILEGV
#define CopFILEGV(c) ((c)->cop_filegv)
#endif
#ifndef CopFILEGV_set
#define CopFILEGV_set(c,gv) ((c)->cop_filegv = (GV*)SvREFCNT_inc(gv))
#endif
#ifndef CopFILE_set
#define CopFILE_set(c,pv) CopFILEGV_set((c), gv_fetchfile(pv))
#endif
#ifndef CopFILESV
#define CopFILESV(c) (CopFILEGV(c) ? GvSV(CopFILEGV(c)) : Nullsv)
#endif
#ifndef CopFILEAV
#define CopFILEAV(c) (CopFILEGV(c) ? GvAV(CopFILEGV(c)) : Nullav)
#endif
#ifndef CopFILE
#define CopFILE(c) (CopFILESV(c) ? SvPVX(CopFILESV(c)) : Nullch)
#endif
#ifndef CopSTASH
#define CopSTASH(c) ((c)->cop_stash)
#endif
#ifndef CopSTASH_set
#define CopSTASH_set(c,hv) ((c)->cop_stash = (hv))
#endif
#ifndef CopSTASHPV
#define CopSTASHPV(c) (CopSTASH(c) ? HvNAME(CopSTASH(c)) : Nullch)
#endif
#ifndef CopSTASHPV_set
#define CopSTASHPV_set(c,pv) CopSTASH_set((c), gv_stashpv(pv,GV_ADD))
#endif
#ifndef CopSTASH_eq
#define CopSTASH_eq(c,hv) (CopSTASH(c) == (hv))
#endif
#endif
#ifndef IN_PERL_COMPILETIME
#define IN_PERL_COMPILETIME (PL_curcop == &PL_compiling)
#endif
#ifndef IN_LOCALE_RUNTIME
#define IN_LOCALE_RUNTIME (PL_curcop->op_private & HINT_LOCALE)
#endif
#ifndef IN_LOCALE_COMPILETIME
#define IN_LOCALE_COMPILETIME (PL_hints & HINT_LOCALE)
#endif
#ifndef IN_LOCALE
#define IN_LOCALE (IN_PERL_COMPILETIME ? IN_LOCALE_COMPILETIME : IN_LOCALE_RUNTIME)
#endif
#ifndef IS_NUMBER_IN_UV
#define IS_NUMBER_IN_UV 0x01
#endif
#ifndef IS_NUMBER_GREATER_THAN_UV_MAX
#define IS_NUMBER_GREATER_THAN_UV_MAX 0x02
#endif
#ifndef IS_NUMBER_NOT_INT
#define IS_NUMBER_NOT_INT 0x04
#endif
#ifndef IS_NUMBER_NEG
#define IS_NUMBER_NEG 0x08
#endif
#ifndef IS_NUMBER_INFINITY
#define IS_NUMBER_INFINITY 0x10
#endif
#ifndef IS_NUMBER_NAN
#define IS_NUMBER_NAN 0x20
#endif
#ifndef GROK_NUMERIC_RADIX
#define GROK_NUMERIC_RADIX(sp, send) grok_numeric_radix(sp, send)
#endif
#ifndef PERL_SCAN_GREATER_THAN_UV_MAX
#define PERL_SCAN_GREATER_THAN_UV_MAX 0x02
#endif
#ifndef PERL_SCAN_SILENT_ILLDIGIT
#define PERL_SCAN_SILENT_ILLDIGIT 0x04
#endif
#ifndef PERL_SCAN_ALLOW_UNDERSCORES
#define PERL_SCAN_ALLOW_UNDERSCORES 0x01
#endif
#ifndef PERL_SCAN_DISALLOW_PREFIX
#define PERL_SCAN_DISALLOW_PREFIX 0x02
#endif
#ifndef grok_numeric_radix
#if defined(NEED_grok_numeric_radix)
static bool DPPP_(my_grok_numeric_radix)(pTHX_ const char ** sp, const char * send);
static
#else
extern bool DPPP_(my_grok_numeric_radix)(pTHX_ const char ** sp, const char * send);
#endif
#ifdef grok_numeric_radix
#undef grok_numeric_radix
#endif
#define grok_numeric_radix(a,b) DPPP_(my_grok_numeric_radix)(aTHX_ a,b)
#define Perl_grok_numeric_radix DPPP_(my_grok_numeric_radix)
#if defined(NEED_grok_numeric_radix) || defined(NEED_grok_numeric_radix_GLOBAL)
bool
DPPP_(my_grok_numeric_radix)(pTHX_ const char **sp, const char *send)
{
#ifdef USE_LOCALE_NUMERIC
#ifdef PL_numeric_radix_sv
if (PL_numeric_radix_sv && IN_LOCALE) {
STRLEN len;
char* radix = SvPV(PL_numeric_radix_sv, len);
if (*sp + len <= send && memEQ(*sp, radix, len)) {
*sp += len;
return TRUE;
}
}
#else
#include <locale.h>
dTHR;
struct lconv *lc = localeconv();
char *radix = lc->decimal_point;
if (radix && IN_LOCALE) {
STRLEN len = strlen(radix);
if (*sp + len <= send && memEQ(*sp, radix, len)) {
*sp += len;
return TRUE;
}
}
#endif
#endif
if (*sp < send && **sp == '.') {
++*sp;
return TRUE;
}
return FALSE;
}
#endif
#endif
#ifndef grok_number
#if defined(NEED_grok_number)
static int DPPP_(my_grok_number)(pTHX_ const char * pv, STRLEN len, UV * valuep);
static
#else
extern int DPPP_(my_grok_number)(pTHX_ const char * pv, STRLEN len, UV * valuep);
#endif
#ifdef grok_number
#undef grok_number
#endif
#define grok_number(a,b,c) DPPP_(my_grok_number)(aTHX_ a,b,c)
#define Perl_grok_number DPPP_(my_grok_number)
#if defined(NEED_grok_number) || defined(NEED_grok_number_GLOBAL)
int
DPPP_(my_grok_number)(pTHX_ const char *pv, STRLEN len, UV *valuep)
{
const char *s = pv;
const char *send = pv + len;
const UV max_div_10 = UV_MAX / 10;
const char max_mod_10 = UV_MAX % 10;
int numtype = 0;
int sawinf = 0;
int sawnan = 0;
while (s < send && isSPACE(*s))
s++;
if (s == send) {
return 0;
} else if (*s == '-') {
s++;
numtype = IS_NUMBER_NEG;
}
else if (*s == '+')
s++;
if (s == send)
return 0;
if (isDIGIT(*s)) {
UV value = *s - '0';
if (++s < send) {
int digit = *s - '0';
if (digit >= 0 && digit <= 9) {
value = value * 10 + digit;
if (++s < send) {
digit = *s - '0';
if (digit >= 0 && digit <= 9) {
value = value * 10 + digit;
if (++s < send) {
digit = *s - '0';
if (digit >= 0 && digit <= 9) {
value = value * 10 + digit;
if (++s < send) {
digit = *s - '0';
if (digit >= 0 && digit <= 9) {
value = value * 10 + digit;
if (++s < send) {
digit = *s - '0';
if (digit >= 0 && digit <= 9) {
value = value * 10 + digit;
if (++s < send) {
digit = *s - '0';
if (digit >= 0 && digit <= 9) {
value = value * 10 + digit;
if (++s < send) {
digit = *s - '0';
if (digit >= 0 && digit <= 9) {
value = value * 10 + digit;
if (++s < send) {
digit = *s - '0';
if (digit >= 0 && digit <= 9) {
value = value * 10 + digit;
if (++s < send) {
digit = *s - '0';
while (digit >= 0 && digit <= 9
&& (value < max_div_10
|| (value == max_div_10
&& digit <= max_mod_10))) {
value = value * 10 + digit;
if (++s < send)
digit = *s - '0';
else
break;
}
if (digit >= 0 && digit <= 9
&& (s < send)) {
do {
s++;
} while (s < send && isDIGIT(*s));
numtype |=
IS_NUMBER_GREATER_THAN_UV_MAX;
goto skip_value;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
numtype |= IS_NUMBER_IN_UV;
if (valuep)
*valuep = value;
skip_value:
if (GROK_NUMERIC_RADIX(&s, send)) {
numtype |= IS_NUMBER_NOT_INT;
while (s < send && isDIGIT(*s))
s++;
}
}
else if (GROK_NUMERIC_RADIX(&s, send)) {
numtype |= IS_NUMBER_NOT_INT | IS_NUMBER_IN_UV;
if (s < send && isDIGIT(*s)) {
do {
s++;
} while (s < send && isDIGIT(*s));
if (valuep) {
*valuep = 0;
}
}
else
return 0;
} else if (*s == 'I' || *s == 'i') {
s++; if (s == send || (*s != 'N' && *s != 'n')) return 0;
s++; if (s == send || (*s != 'F' && *s != 'f')) return 0;
s++; if (s < send && (*s == 'I' || *s == 'i')) {
s++; if (s == send || (*s != 'N' && *s != 'n')) return 0;
s++; if (s == send || (*s != 'I' && *s != 'i')) return 0;
s++; if (s == send || (*s != 'T' && *s != 't')) return 0;
s++; if (s == send || (*s != 'Y' && *s != 'y')) return 0;
s++;
}
sawinf = 1;
} else if (*s == 'N' || *s == 'n') {
s++; if (s == send || (*s != 'A' && *s != 'a')) return 0;
s++; if (s == send || (*s != 'N' && *s != 'n')) return 0;
s++;
sawnan = 1;
} else
return 0;
if (sawinf) {
numtype &= IS_NUMBER_NEG;
numtype |= IS_NUMBER_INFINITY | IS_NUMBER_NOT_INT;
} else if (sawnan) {
numtype &= IS_NUMBER_NEG;
numtype |= IS_NUMBER_NAN | IS_NUMBER_NOT_INT;
} else if (s < send) {
if (*s == 'e' || *s == 'E') {
numtype &= IS_NUMBER_NEG;
numtype |= IS_NUMBER_NOT_INT;
s++;
if (s < send && (*s == '-' || *s == '+'))
s++;
if (s < send && isDIGIT(*s)) {
do {
s++;
} while (s < send && isDIGIT(*s));
}
else
return 0;
}
}
while (s < send && isSPACE(*s))
s++;
if (s >= send)
return numtype;
if (len == 10 && memEQ(pv, "0 but true", 10)) {
if (valuep)
*valuep = 0;
return IS_NUMBER_IN_UV;
}
return 0;
}
#endif
#endif
#ifndef grok_bin
#if defined(NEED_grok_bin)
static UV DPPP_(my_grok_bin)(pTHX_ char *start, STRLEN *len_p, I32 *flags, NV *result);
static
#else
extern UV DPPP_(my_grok_bin)(pTHX_ char *start, STRLEN *len_p, I32 *flags, NV *result);
#endif
#ifdef grok_bin
#undef grok_bin
#endif
#define grok_bin(a,b,c,d) DPPP_(my_grok_bin)(aTHX_ a,b,c,d)
#define Perl_grok_bin DPPP_(my_grok_bin)
#if defined(NEED_grok_bin) || defined(NEED_grok_bin_GLOBAL)
UV
DPPP_(my_grok_bin)(pTHX_ char *start, STRLEN *len_p, I32 *flags, NV *result)
{
const char *s = start;
STRLEN len = *len_p;
UV value = 0;
NV value_nv = 0;
const UV max_div_2 = UV_MAX / 2;
bool allow_underscores = *flags & PERL_SCAN_ALLOW_UNDERSCORES;
bool overflowed = FALSE;
if (!(*flags & PERL_SCAN_DISALLOW_PREFIX)) {
if (len >= 1) {
if (s[0] == 'b') {
s++;
len--;
}
else if (len >= 2 && s[0] == '0' && s[1] == 'b') {
s+=2;
len-=2;
}
}
}
for (; len-- && *s; s++) {
char bit = *s;
if (bit == '0' || bit == '1') {
redo:
if (!overflowed) {
if (value <= max_div_2) {
value = (value << 1) | (bit - '0');
continue;
}
warn("Integer overflow in binary number");
overflowed = TRUE;
value_nv = (NV) value;
}
value_nv *= 2.0;
value_nv += (NV)(bit - '0');
continue;
}
if (bit == '_' && len && allow_underscores && (bit = s[1])
&& (bit == '0' || bit == '1'))
{
--len;
++s;
goto redo;
}
if (!(*flags & PERL_SCAN_SILENT_ILLDIGIT))
warn("Illegal binary digit '%c' ignored", *s);
break;
}
if ( ( overflowed && value_nv > 4294967295.0)
#if UVSIZE > 4
|| (!overflowed && value > 0xffffffff )
#endif
) {
warn("Binary number > 0b11111111111111111111111111111111 non-portable");
}
*len_p = s - start;
if (!overflowed) {
*flags = 0;
return value;
}
*flags = PERL_SCAN_GREATER_THAN_UV_MAX;
if (result)
*result = value_nv;
return UV_MAX;
}
#endif
#endif
#ifndef grok_hex
#if defined(NEED_grok_hex)
static UV DPPP_(my_grok_hex)(pTHX_ char *start, STRLEN *len_p, I32 *flags, NV *result);
static
#else
extern UV DPPP_(my_grok_hex)(pTHX_ char *start, STRLEN *len_p, I32 *flags, NV *result);
#endif
#ifdef grok_hex
#undef grok_hex
#endif
#define grok_hex(a,b,c,d) DPPP_(my_grok_hex)(aTHX_ a,b,c,d)
#define Perl_grok_hex DPPP_(my_grok_hex)
#if defined(NEED_grok_hex) || defined(NEED_grok_hex_GLOBAL)
UV
DPPP_(my_grok_hex)(pTHX_ char *start, STRLEN *len_p, I32 *flags, NV *result)
{
const char *s = start;
STRLEN len = *len_p;
UV value = 0;
NV value_nv = 0;
const UV max_div_16 = UV_MAX / 16;
bool allow_underscores = *flags & PERL_SCAN_ALLOW_UNDERSCORES;
bool overflowed = FALSE;
const char *xdigit;
if (!(*flags & PERL_SCAN_DISALLOW_PREFIX)) {
if (len >= 1) {
if (s[0] == 'x') {
s++;
len--;
}
else if (len >= 2 && s[0] == '0' && s[1] == 'x') {
s+=2;
len-=2;
}
}
}
for (; len-- && *s; s++) {
xdigit = strchr((char *) PL_hexdigit, *s);
if (xdigit) {
redo:
if (!overflowed) {
if (value <= max_div_16) {
value = (value << 4) | ((xdigit - PL_hexdigit) & 15);
continue;
}
warn("Integer overflow in hexadecimal number");
overflowed = TRUE;
value_nv = (NV) value;
}
value_nv *= 16.0;
value_nv += (NV)((xdigit - PL_hexdigit) & 15);
continue;
}
if (*s == '_' && len && allow_underscores && s[1]
&& (xdigit = strchr((char *) PL_hexdigit, s[1])))
{
--len;
++s;
goto redo;
}
if (!(*flags & PERL_SCAN_SILENT_ILLDIGIT))
warn("Illegal hexadecimal digit '%c' ignored", *s);
break;
}
if ( ( overflowed && value_nv > 4294967295.0)
#if UVSIZE > 4
|| (!overflowed && value > 0xffffffff )
#endif
) {
warn("Hexadecimal number > 0xffffffff non-portable");
}
*len_p = s - start;
if (!overflowed) {
*flags = 0;
return value;
}
*flags = PERL_SCAN_GREATER_THAN_UV_MAX;
if (result)
*result = value_nv;
return UV_MAX;
}
#endif
#endif
#ifndef grok_oct
#if defined(NEED_grok_oct)
static UV DPPP_(my_grok_oct)(pTHX_ char *start, STRLEN *len_p, I32 *flags, NV *result);
static
#else
extern UV DPPP_(my_grok_oct)(pTHX_ char *start, STRLEN *len_p, I32 *flags, NV *result);
#endif
#ifdef grok_oct
#undef grok_oct
#endif
#define grok_oct(a,b,c,d) DPPP_(my_grok_oct)(aTHX_ a,b,c,d)
#define Perl_grok_oct DPPP_(my_grok_oct)
#if defined(NEED_grok_oct) || defined(NEED_grok_oct_GLOBAL)
UV
DPPP_(my_grok_oct)(pTHX_ char *start, STRLEN *len_p, I32 *flags, NV *result)
{
const char *s = start;
STRLEN len = *len_p;
UV value = 0;
NV value_nv = 0;
const UV max_div_8 = UV_MAX / 8;
bool allow_underscores = *flags & PERL_SCAN_ALLOW_UNDERSCORES;
bool overflowed = FALSE;
for (; len-- && *s; s++) {
int digit = *s - '0';
if (digit >= 0 && digit <= 7) {
redo:
if (!overflowed) {
if (value <= max_div_8) {
value = (value << 3) | digit;
continue;
}
warn("Integer overflow in octal number");
overflowed = TRUE;
value_nv = (NV) value;
}
value_nv *= 8.0;
value_nv += (NV)digit;
continue;
}
if (digit == ('_' - '0') && len && allow_underscores
&& (digit = s[1] - '0') && (digit >= 0 && digit <= 7))
{
--len;
++s;
goto redo;
}
if (digit == 8 || digit == 9) {
if (!(*flags & PERL_SCAN_SILENT_ILLDIGIT))
warn("Illegal octal digit '%c' ignored", *s);
}
break;
}
if ( ( overflowed && value_nv > 4294967295.0)
#if UVSIZE > 4
|| (!overflowed && value > 0xffffffff )
#endif
) {
warn("Octal number > 037777777777 non-portable");
}
*len_p = s - start;
if (!overflowed) {
*flags = 0;
return value;
}
*flags = PERL_SCAN_GREATER_THAN_UV_MAX;
if (result)
*result = value_nv;
return UV_MAX;
}
#endif
#endif
#if !defined(my_snprintf)
#if defined(NEED_my_snprintf)
static int DPPP_(my_my_snprintf)(char * buffer, const Size_t len, const char * format, ...);
static
#else
extern int DPPP_(my_my_snprintf)(char * buffer, const Size_t len, const char * format, ...);
#endif
#define my_snprintf DPPP_(my_my_snprintf)
#define Perl_my_snprintf DPPP_(my_my_snprintf)
#if defined(NEED_my_snprintf) || defined(NEED_my_snprintf_GLOBAL)
int
DPPP_(my_my_snprintf)(char *buffer, const Size_t len, const char *format, ...)
{
dTHX;
int retval;
va_list ap;
va_start(ap, format);
#ifdef HAS_VSNPRINTF
retval = vsnprintf(buffer, len, format, ap);
#else
retval = vsprintf(buffer, format, ap);
#endif
va_end(ap);
if (retval >= (int)len)
Perl_croak(aTHX_ "panic: my_snprintf buffer overflow");
return retval;
}
#endif
#endif
#ifdef NO_XSLOCKS
#ifdef dJMPENV
#define dXCPT dJMPENV; int rEtV = 0
#define XCPT_TRY_START JMPENV_PUSH(rEtV); if (rEtV == 0)
#define XCPT_TRY_END JMPENV_POP;
#define XCPT_CATCH if (rEtV != 0)
#define XCPT_RETHROW JMPENV_JUMP(rEtV)
#else
#define dXCPT Sigjmp_buf oldTOP; int rEtV = 0
#define XCPT_TRY_START Copy(top_env, oldTOP, 1, Sigjmp_buf); rEtV = Sigsetjmp(top_env, 1); if (rEtV == 0)
#define XCPT_TRY_END Copy(oldTOP, top_env, 1, Sigjmp_buf);
#define XCPT_CATCH if (rEtV != 0)
#define XCPT_RETHROW Siglongjmp(top_env, rEtV)
#endif
#endif
#if !defined(my_strlcat)
#if defined(NEED_my_strlcat)
static Size_t DPPP_(my_my_strlcat)(char * dst, const char * src, Size_t size);
static
#else
extern Size_t DPPP_(my_my_strlcat)(char * dst, const char * src, Size_t size);
#endif
#define my_strlcat DPPP_(my_my_strlcat)
#define Perl_my_strlcat DPPP_(my_my_strlcat)
#if defined(NEED_my_strlcat) || defined(NEED_my_strlcat_GLOBAL)
Size_t
DPPP_(my_my_strlcat)(char *dst, const char *src, Size_t size)
{
Size_t used, length, copy;
used = strlen(dst);
length = strlen(src);
if (size > 0 && used < size - 1) {
copy = (length >= size - used) ? size - used - 1 : length;
memcpy(dst + used, src, copy);
dst[used + copy] = '\0';
}
return used + length;
}
#endif
#endif
#if !defined(my_strlcpy)
#if defined(NEED_my_strlcpy)
static Size_t DPPP_(my_my_strlcpy)(char * dst, const char * src, Size_t size);
static
#else
extern Size_t DPPP_(my_my_strlcpy)(char * dst, const char * src, Size_t size);
#endif
#define my_strlcpy DPPP_(my_my_strlcpy)
#define Perl_my_strlcpy DPPP_(my_my_strlcpy)
#if defined(NEED_my_strlcpy) || defined(NEED_my_strlcpy_GLOBAL)
Size_t
DPPP_(my_my_strlcpy)(char *dst, const char *src, Size_t size)
{
Size_t length, copy;
length = strlen(src);
if (size > 0) {
copy = (length >= size) ? size - 1 : length;
memcpy(dst, src, copy);
dst[copy] = '\0';
}
return length;
}
#endif
#endif
#endif
