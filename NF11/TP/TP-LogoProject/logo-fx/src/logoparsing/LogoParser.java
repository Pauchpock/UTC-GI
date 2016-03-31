// Generated from grammar/Logo.g4 by ANTLR 4.5

  package logoparsing;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class LogoParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.5", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, INT=12, WS=13;
	public static final int
		RULE_programme = 0, RULE_liste_instructions = 1, RULE_instruction = 2;
	public static final String[] ruleNames = {
		"programme", "liste_instructions", "instruction"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'av'", "'td'", "'tg'", "'lc'", "'bc'", "'ve'", "'re'", "'fpos'", 
		"'['", "']'", "'fcc'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, null, null, null, null, 
		"INT", "WS"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Logo.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public LogoParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class ProgrammeContext extends ParserRuleContext {
		public Liste_instructionsContext liste_instructions() {
			return getRuleContext(Liste_instructionsContext.class,0);
		}
		public ProgrammeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_programme; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterProgramme(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitProgramme(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitProgramme(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProgrammeContext programme() throws RecognitionException {
		ProgrammeContext _localctx = new ProgrammeContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_programme);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(6);
			liste_instructions();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Liste_instructionsContext extends ParserRuleContext {
		public List<InstructionContext> instruction() {
			return getRuleContexts(InstructionContext.class);
		}
		public InstructionContext instruction(int i) {
			return getRuleContext(InstructionContext.class,i);
		}
		public Liste_instructionsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_liste_instructions; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterListe_instructions(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitListe_instructions(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitListe_instructions(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Liste_instructionsContext liste_instructions() throws RecognitionException {
		Liste_instructionsContext _localctx = new Liste_instructionsContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_liste_instructions);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(9); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(8);
				instruction();
				}
				}
				setState(11); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << T__2) | (1L << T__3) | (1L << T__4) | (1L << T__5) | (1L << T__6) | (1L << T__7) | (1L << T__10))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InstructionContext extends ParserRuleContext {
		public InstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_instruction; }
	 
		public InstructionContext() { }
		public void copyFrom(InstructionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class TdContext extends InstructionContext {
		public TerminalNode INT() { return getToken(LogoParser.INT, 0); }
		public TdContext(InstructionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterTd(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitTd(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitTd(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class BcContext extends InstructionContext {
		public BcContext(InstructionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterBc(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitBc(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitBc(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class TgContext extends InstructionContext {
		public TerminalNode INT() { return getToken(LogoParser.INT, 0); }
		public TgContext(InstructionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterTg(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitTg(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitTg(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class ReContext extends InstructionContext {
		public TerminalNode INT() { return getToken(LogoParser.INT, 0); }
		public ReContext(InstructionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterRe(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitRe(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitRe(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AvContext extends InstructionContext {
		public TerminalNode INT() { return getToken(LogoParser.INT, 0); }
		public AvContext(InstructionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterAv(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitAv(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitAv(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class LcContext extends InstructionContext {
		public LcContext(InstructionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterLc(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitLc(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitLc(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class FccContext extends InstructionContext {
		public TerminalNode INT() { return getToken(LogoParser.INT, 0); }
		public FccContext(InstructionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterFcc(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitFcc(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitFcc(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class FposContext extends InstructionContext {
		public List<TerminalNode> INT() { return getTokens(LogoParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(LogoParser.INT, i);
		}
		public FposContext(InstructionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterFpos(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitFpos(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitFpos(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class VeContext extends InstructionContext {
		public VeContext(InstructionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).enterVe(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LogoListener ) ((LogoListener)listener).exitVe(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LogoVisitor ) return ((LogoVisitor<? extends T>)visitor).visitVe(this);
			else return visitor.visitChildren(this);
		}
	}

	public final InstructionContext instruction() throws RecognitionException {
		InstructionContext _localctx = new InstructionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_instruction);
		try {
			setState(31);
			switch (_input.LA(1)) {
			case T__0:
				_localctx = new AvContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(13);
				match(T__0);
				setState(14);
				match(INT);
				}
				break;
			case T__1:
				_localctx = new TdContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(15);
				match(T__1);
				setState(16);
				match(INT);
				}
				break;
			case T__2:
				_localctx = new TgContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(17);
				match(T__2);
				setState(18);
				match(INT);
				}
				break;
			case T__3:
				_localctx = new LcContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(19);
				match(T__3);
				}
				break;
			case T__4:
				_localctx = new BcContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(20);
				match(T__4);
				}
				break;
			case T__5:
				_localctx = new VeContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(21);
				match(T__5);
				}
				break;
			case T__6:
				_localctx = new ReContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(22);
				match(T__6);
				setState(23);
				match(INT);
				}
				break;
			case T__7:
				_localctx = new FposContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(24);
				match(T__7);
				setState(25);
				match(T__8);
				setState(26);
				match(INT);
				setState(27);
				match(INT);
				setState(28);
				match(T__9);
				}
				break;
			case T__10:
				_localctx = new FccContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(29);
				match(T__10);
				setState(30);
				match(INT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3\17$\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\3\2\3\2\3\3\6\3\f\n\3\r\3\16\3\r\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4\"\n\4\3\4\2\2\5\2\4"+
		"\6\2\2)\2\b\3\2\2\2\4\13\3\2\2\2\6!\3\2\2\2\b\t\5\4\3\2\t\3\3\2\2\2\n"+
		"\f\5\6\4\2\13\n\3\2\2\2\f\r\3\2\2\2\r\13\3\2\2\2\r\16\3\2\2\2\16\5\3\2"+
		"\2\2\17\20\7\3\2\2\20\"\7\16\2\2\21\22\7\4\2\2\22\"\7\16\2\2\23\24\7\5"+
		"\2\2\24\"\7\16\2\2\25\"\7\6\2\2\26\"\7\7\2\2\27\"\7\b\2\2\30\31\7\t\2"+
		"\2\31\"\7\16\2\2\32\33\7\n\2\2\33\34\7\13\2\2\34\35\7\16\2\2\35\36\7\16"+
		"\2\2\36\"\7\f\2\2\37 \7\r\2\2 \"\7\16\2\2!\17\3\2\2\2!\21\3\2\2\2!\23"+
		"\3\2\2\2!\25\3\2\2\2!\26\3\2\2\2!\27\3\2\2\2!\30\3\2\2\2!\32\3\2\2\2!"+
		"\37\3\2\2\2\"\7\3\2\2\2\4\r!";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}