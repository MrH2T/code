#include<bits/stdc++.h>

#define SHI_YONG using
#define MIN_MING_KONG_JIAN namespace
#define CHONG_FU for
#define CHANG long
#define ZHENG_SHU CHANG CHANG
#define ZI_FU char
#define FAN_HUI return
#define du_zi_fu getchar
#define CHANG_LIANG const
#define YOU_FU_HAO signed
#define KONG void
#define JIE_GOU struct
#define DANG while
#define RU_GUO if
#define FOU_ZE else
#define SHU_ZU vector
#define DUI_ZI pair
#define di_yi_ge first
#define di_er_ge second
#define xia_er_fen lower_bound
#define zhu_han_shu main
#define FU_ZHI memcpy
#define PAI_XU sort
#define QU_CHONG unique
#define DE_DA_XIAO sizeof
#define ZUO_YI_DUI make_pair
#define WANG_HOU_TUI push_back
#define SHU_CHU printf

#define CHONG(mou,jia,yi,ding,bing) CHONG_FU(ZHENG_SHU mou=jia;mou<=yi&&bing;mou+=ding)
#define FU(mou,jia,yi,ding,bing) CHONG_FU(ZHENG_SHU mou=jia;mou>=yi&&bing;mou-=ding)
SHI_YONG MIN_MING_KONG_JIAN std;
inline ZHENG_SHU DU_RU(){
    ZI_FU zi_fu=0,fu_hao=1;ZHENG_SHU jie_guo=0;
    DANG(zi_fu<'0'||zi_fu>'9'&&zi_fu!='-')((zi_fu=du_zi_fu())=='-')&&(fu_hao=-fu_hao);
    DANG(zi_fu>='0'&&zi_fu<='9')jie_guo=(jie_guo<<1)+(jie_guo<<3)+(zi_fu^48),zi_fu=du_zi_fu();
    FAN_HUI jie_guo*fu_hao;
}
CHANG_LIANG ZHENG_SHU ZUI_DA_DE_N = 100050;
ZHENG_SHU dian_shu,da_xiao;
YOU_FU_HAO shu_liang,tou[ZUI_DA_DE_N],dao_da[ZUI_DA_DE_N<<1],zhi[ZUI_DA_DE_N<<1],xia_yi_tiao[ZUI_DA_DE_N<<1];
KONG jia_bian(ZHENG_SHU jia,ZHENG_SHU yi,ZHENG_SHU bing){
    xia_yi_tiao[++shu_liang]=tou[jia],tou[jia]=shu_liang,dao_da[shu_liang]=yi,zhi[shu_liang]=bing;
}
ZHENG_SHU he[ZUI_DA_DE_N];
MIN_MING_KONG_JIAN Xian_duan_shu{
    JIE_GOU Jie_dian{
        YOU_FU_HAO zuo_er_zi,you_er_zi;
        YOU_FU_HAO shu_liang;
        ZHENG_SHU he;
    }shu[ZUI_DA_DE_N<<5];
    #define zuo_er_zi(dian) shu[dian].zuo_er_zi
    #define you_er_zi(dian) shu[dian].you_er_zi
    #define shu_liang(dian) shu[dian].shu_liang
    #define he(dian) shu[dian].he
    YOU_FU_HAO shu_liang_yi,gen[ZUI_DA_DE_N];
    KONG xiang_shang(ZHENG_SHU dian){
        shu_liang(dian)=shu_liang(zuo_er_zi(dian))+shu_liang(you_er_zi(dian));
        he(dian)=he(zuo_er_zi(dian))+he(you_er_zi(dian));
    }
    KONG he_bing(YOU_FU_HAO &gen_jia,YOU_FU_HAO gen_yi){
        RU_GUO(!gen_jia||!gen_yi)FAN_HUI KONG(gen_jia+=gen_yi);
        he(gen_jia)+=he(gen_yi),shu_liang(gen_jia)+=shu_liang(gen_yi);
        he_bing(zuo_er_zi(gen_jia),zuo_er_zi(gen_yi)),he_bing(you_er_zi(gen_jia),you_er_zi(gen_yi));
    }
    KONG jia(YOU_FU_HAO &gen,ZHENG_SHU zuo,ZHENG_SHU you,ZHENG_SHU wei_zhi,ZHENG_SHU zhi){
        RU_GUO(!gen)gen=++shu_liang_yi;
        RU_GUO(zuo==you){
            shu_liang(gen)++,he(gen)+=zhi;
            FAN_HUI;
        }
        ZHENG_SHU zhong=zuo+you>>1;
        RU_GUO(wei_zhi<=zhong)jia(zuo_er_zi(gen),zuo,zhong,wei_zhi,zhi);
        FOU_ZE jia(you_er_zi(gen),zhong+1,you,wei_zhi,zhi);
        xiang_shang(gen);
    }
    ZHENG_SHU xun_wen(ZHENG_SHU gen,ZHENG_SHU zuo,ZHENG_SHU you,ZHENG_SHU zuo_yi,ZHENG_SHU you_yi,ZHENG_SHU biao_zhi){
        RU_GUO(zuo_yi>you_yi||!gen)FAN_HUI 0;
        RU_GUO(zuo_yi<=zuo&&you<=you_yi)FAN_HUI !biao_zhi?shu_liang(gen):he(gen);
        ZHENG_SHU zhong=zuo+you>>1,jie_guo=0;
        RU_GUO(zuo_yi<=zhong)jie_guo+=xun_wen(zuo_er_zi(gen),zuo,zhong,zuo_yi,you_yi,biao_zhi);
        RU_GUO(you_yi>zhong)jie_guo+=xun_wen(you_er_zi(gen),zhong+1,you,zuo_yi,you_yi,biao_zhi);
        FAN_HUI jie_guo;
    }
}
ZHENG_SHU lin_shi_shu_zu[ZUI_DA_DE_N],bian_hao[ZUI_DA_DE_N];
KONG sou_suo(ZHENG_SHU dian,ZHENG_SHU fu_qing){
    CHONG_FU(ZHENG_SHU mou=tou[dian],er_zi;mou;mou=xia_yi_tiao[mou])RU_GUO((er_zi=dao_da[mou])!=fu_qing){
        he[er_zi]=he[dian]+zhi[mou];
        sou_suo(er_zi,dian);
    }
}
SHU_ZU<DUI_ZI<ZHENG_SHU,ZHENG_SHU> > xun_wen[ZUI_DA_DE_N];
ZHENG_SHU da_an[ZUI_DA_DE_N];
KONG sou_suo_yi(ZHENG_SHU dian,ZHENG_SHU fu_qing){
    Xian_duan_shu::jia(Xian_duan_shu::gen[dian],1,da_xiao,bian_hao[dian],he[dian]);
    CHONG_FU(ZHENG_SHU mou=tou[dian],er_zi;mou;mou=xia_yi_tiao[mou])RU_GUO((er_zi=dao_da[mou])!=fu_qing){
        sou_suo_yi(er_zi,dian);
        Xian_duan_shu::he_bing(Xian_duan_shu::gen[dian],Xian_duan_shu::gen[er_zi]);
    }
    CHONG_FU(DUI_ZI<ZHENG_SHU,ZHENG_SHU> mou_ge_xun_wen:xun_wen[dian]){
        ZHENG_SHU zhi_yi=mou_ge_xun_wen.di_er_ge+he[dian];
        ZHENG_SHU wei_zhi=xia_er_fen(lin_shi_shu_zu+1,lin_shi_shu_zu+da_xiao+1,zhi_yi)-lin_shi_shu_zu;
        da_an[mou_ge_xun_wen.di_yi_ge]=
            Xian_duan_shu::xun_wen(Xian_duan_shu::gen[dian],1,da_xiao,wei_zhi,da_xiao,1)
            -he[dian]*Xian_duan_shu::xun_wen(Xian_duan_shu::gen[dian],1,da_xiao,wei_zhi,da_xiao,0);
    }
}
YOU_FU_HAO zhu_han_shu(){
//    freopen("dat.in","r",stdin);
//    freopen("me.out","w",stdout);
    dian_shu=DU_RU();
//    memset(Seg::tr,0,sizeof(Seg::tr));
    CHONG(mou,2,dian_shu,1,1){
        ZHENG_SHU ba_ba=DU_RU(),bian_quan=DU_RU();
        jia_bian(mou,ba_ba,bian_quan),jia_bian(ba_ba,mou,bian_quan);
    }
    sou_suo(1,0);
    FU_ZHI(lin_shi_shu_zu,he,DE_DA_XIAO(he)),PAI_XU(lin_shi_shu_zu+1,lin_shi_shu_zu+dian_shu+1);
    da_xiao=QU_CHONG(lin_shi_shu_zu+1,lin_shi_shu_zu+dian_shu+1)-lin_shi_shu_zu-1;
	CHONG(mou,1,dian_shu,1,1)bian_hao[mou]=xia_er_fen(lin_shi_shu_zu+1,lin_shi_shu_zu+da_xiao+1,he[mou])-lin_shi_shu_zu;
    ZHENG_SHU xun_wen_shu=DU_RU();
    CHONG(mou,1,xun_wen_shu,1,1){
        ZHENG_SHU dian=DU_RU(),zhi=DU_RU();
        xun_wen[dian].WANG_HOU_TUI(ZUO_YI_DUI(dian,zhi));
    }
    sou_suo_yi(1,0);
    CHONG(mou,1,xun_wen_shu,1,1)SHU_CHU("%lld\n",da_an[mou]);
}
