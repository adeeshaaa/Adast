// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2018 LightPayCoin developers
// Copyright (c) 2019 The Adast developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
        (     0, uint256("0x000001224e87559db2f12ca021ee8f950fa33eb9754cb5d4255bd36925d6533f"))
        (   100, uint256("0x00000e84f69ceafa09bb88996e2e01342d86ab9fce9b8584fd5bfbdc6492262b"))
        (  1000, uint256("0x419abc36596a20903d8ffeb0d10373de224e3c8664a73eccb5499fc6d863a28f"))
	    (  5000, uint256("0x55f2c9e9c5c77ab4638c16e406cd9a6ddcacb7ee9e8db7406659d99ec79211ab"))
	    ( 10000, uint256("0x0315b09f2996d6a30112fee0343e54183bdce6af13c5ee713dc6a942719d960a"))
	    ( 20000, uint256("0x5b774379a76442cc1139b62e65f9c43aceb30b71b2bbea66d5a36a66db79e481"))
	    ( 25550, uint256("0xa6490faa1cfe00d6326e4137dfa03af63d161a6f064ac12b2b1328a0cffa70ec"))
        ( 29800, uint256("0xca520b9ea160c61d5f20362a743c0fd9a000c892468825ba2bb18c8da4d1b618"))
        ( 35000, uint256("0xdbf3a20afca18d81a68c25a8b120a463044e515cc7c2aa6e8e1ca0c2c8c60f24"))
	    ( 65000, uint256("0xe5005cfc3025b6e4220766d22d23e78e006812e1f3831f013f8b85b629a019bb"))
	    ( 85000, uint256("0x7a1be2dfd4d350bebaaff34e9dec91c62db8c2f63364a5d23af83b988c137ee4"))
	    ( 88645, uint256("0xc5e668c9ad60abdef77367b57c17764a97c78721614c56e530675e24ba0d3df1"))
	    ( 90000, uint256("0x1a587150c5722f5abd56bc8f5968d7b3e4afc81958074d901385200242dca9ab"))
	    (100000, uint256("0xf7006d132c3543f5dd72d4214ad3425bf384d8deb7ef8c6d36e9d9fc3cb9cecc"))
	    (110000, uint256("0xbfef690d4ca7110d97efa3d0f31cd198fc5fe44aa934270e66b85bf32e3d6659"))
	    (120000, uint256("0x3d9f82de83f9ec9bf23c89d18e8b561976ad41c357c353ee409cb5ae9f7fce93"))
	    (130000, uint256("0xe482b49afda85e2d3fa208c3448d5419a91616a17d20b9b4c8d8dd637c5a1c44"))
	    (135457, uint256("0xf0913f5ae775b2294f49d9dd73ef9b4c0b68c46e97e80c556f0b6bd11d7c9ac0"))
        ;

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1587612668, // * UNIX timestamp of last checkpoint block
    311275,     // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
        (0, uint256("0"));

static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1553555506,
    0,
    2000};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1553555506,
    0,
    100};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        pchMessageStart[0] = 0xf3;
        pchMessageStart[1] = 0xde;
        pchMessageStart[2] = 0x01;
        pchMessageStart[3] = 0xd6;
        vAlertPubKey = ParseHex("0438d21f5d5e1677c2805e2b623faf4c530214efeaafec04802aafe1895936a12741794eeb06d964196ab84bac40b7885b7b2c1b5824fb157591a84b13835d23ad");
        nDefaultPort = 23452;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Adast starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 9999999;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 2 * 60;
        nTargetSpacing = 2 * 60;
        nLastPOWBlock = 200;
        nMaturity = 20;
        nMasternodeCountDrift = 20;
        nMasternodeCollateralLimit = 200000;
        nModifierUpdateBlock = 100000;
        nMaxMoneyOut = 10000000000 * COIN;
        const char* pszTimestamp = "Iran retaliates with missile strike on US forces in Iraq - CNN";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 1 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("049c4bf0b18b4b968c1136fa1fed29a02192eb4f7d249975e71dd955d6672c3b883e3f60442846747039b1065fb56c89177df6b09b46f71c8f8a02b7807aa42e42") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1578497190;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 21426443;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000288b54877a22e7075c8938be919095b743246f598c9bf46916aa13d344f"));
        assert(genesis.hashMerkleRoot == uint256("0xc1527f8b6a4c435e8588a10abc28ad3a2265dad7c94174ad424a1fd7a0a63223"));

        vSeeds.push_back(CDNSSeedData("seed1.adastproject.com", "seed1.adastproject.com"));
        vSeeds.push_back(CDNSSeedData("seed2.adastproject.com", "seed2.adastproject.com"));
        vSeeds.push_back(CDNSSeedData("seed3.adastproject.com", "seed3.adastproject.com"));
        vSeeds.push_back(CDNSSeedData("seed4.adastproject.com", "seed4.adastproject.com"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 23); // A
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 73); // W
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 128);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;       // default true
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;       // default false
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "04bd8d3e45f1c7fc1d34ce4c27356d3a5f43e1dfaf061e2152bbb68279741ab7197b4e74a81bea32ccd5f3b3f414a0cfa34a9c8ec747709897bb1fb8aea51fdcc0";
        strObfuscationPoolDummyAddress = "NQTuqzbn3aVbfQvFEFAHJFHoNB68JsVjr7";
        nStartMasternodePayments = 1578497190;

    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x41;
        pchMessageStart[1] = 0x4d;
        pchMessageStart[2] = 0x5e;
        pchMessageStart[3] = 0x78;
        vAlertPubKey = ParseHex("049c4bf0b18b4b968c1136fa1fed29a02192eb4f7d249975e71dd955d6672c3b883e3f60442846747039b1065fb56c89177df6b09b46f71c8f8a02b7807aa42e42");
        nDefaultPort = 39795;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Adast: 1 day
        nTargetSpacing = 1 * 60;  // Adast: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nMasternodeCollateralLimit = 10000;
        nModifierUpdateBlock = 500;
        nMaxMoneyOut = 43199500 * COIN;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1578497190;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 21426443;


        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x00000288b54877a22e7075c8938be919095b743246f598c9bf46916aa13d344f"));
        assert(genesis.hashMerkleRoot == uint256("0xc1527f8b6a4c435e8588a10abc28ad3a2265dad7c94174ad424a1fd7a0a63223"));

        vFixedSeeds.clear();
        vSeeds.clear();

        vSeeds.push_back(CDNSSeedData("1", "45.76.123.6"));         // Single node address

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet Adast addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet Adast script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet Adast BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet Adast BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet Adast BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = true;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04f25f195facbb086a0ad67a94bbe4e8cc3e805224ae595fea0b0ac0ffe6199e1559dfc536369b13839271060a58799255d9e3d928a085333093685ffc4f73c02f";
        strObfuscationPoolDummyAddress = "xxVKdbxVogrXrPLMo2qEEyCm1GRv2KZCLy";
        nStartMasternodePayments = 1524873600; //Fri, 09 Jan 2015 21:05:58 GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x2d;
        pchMessageStart[1] = 0x53;
        pchMessageStart[2] = 0x6f;
        pchMessageStart[3] = 0x40;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Adast: 1 day
        nTargetSpacing = 1 * 60;        // Adast: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1578497190;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 906460;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 39793;
        // assert(hashGenesisBlock == uint256("00000d885e2813770fd59e71010b6b62a9b0609655109bf4e1b24c3bd524ae0c"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 39791;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
