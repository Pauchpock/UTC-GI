// Generated from grammar/Logo.g4 by ANTLR 4.5

  package logoparsing;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class LogoLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.5", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, INT=19, WS=20;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
		"T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
		"T__17", "INT", "WS"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'av'", "'td'", "'tg'", "'lc'", "'bc'", "'ve'", "'re'", "'fpos'", 
		"'['", "']'", "'fcc'", "'*'", "'/'", "'+'", "'-'", "'hasard'", "'('", 
		"')'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, "INT", "WS"
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


	public LogoLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Logo.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\26q\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\3\2\3\2\3\2\3\3\3\3\3\3\3\4\3\4\3\4\3\5"+
		"\3\5\3\5\3\6\3\6\3\6\3\7\3\7\3\7\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\n\3"+
		"\n\3\13\3\13\3\f\3\f\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20\3\20\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\24\7\24"+
		"d\n\24\f\24\16\24g\13\24\5\24i\n\24\3\25\6\25l\n\25\r\25\16\25m\3\25\3"+
		"\25\2\2\26\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33"+
		"\17\35\20\37\21!\22#\23%\24\'\25)\26\3\2\5\3\2\63;\3\2\62;\5\2\13\f\17"+
		"\17\"\"s\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2"+
		"\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27"+
		"\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2"+
		"\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\3+\3\2\2\2\5.\3\2\2\2"+
		"\7\61\3\2\2\2\t\64\3\2\2\2\13\67\3\2\2\2\r:\3\2\2\2\17=\3\2\2\2\21@\3"+
		"\2\2\2\23E\3\2\2\2\25G\3\2\2\2\27I\3\2\2\2\31M\3\2\2\2\33O\3\2\2\2\35"+
		"Q\3\2\2\2\37S\3\2\2\2!U\3\2\2\2#\\\3\2\2\2%^\3\2\2\2\'h\3\2\2\2)k\3\2"+
		"\2\2+,\7c\2\2,-\7x\2\2-\4\3\2\2\2./\7v\2\2/\60\7f\2\2\60\6\3\2\2\2\61"+
		"\62\7v\2\2\62\63\7i\2\2\63\b\3\2\2\2\64\65\7n\2\2\65\66\7e\2\2\66\n\3"+
		"\2\2\2\678\7d\2\289\7e\2\29\f\3\2\2\2:;\7x\2\2;<\7g\2\2<\16\3\2\2\2=>"+
		"\7t\2\2>?\7g\2\2?\20\3\2\2\2@A\7h\2\2AB\7r\2\2BC\7q\2\2CD\7u\2\2D\22\3"+
		"\2\2\2EF\7]\2\2F\24\3\2\2\2GH\7_\2\2H\26\3\2\2\2IJ\7h\2\2JK\7e\2\2KL\7"+
		"e\2\2L\30\3\2\2\2MN\7,\2\2N\32\3\2\2\2OP\7\61\2\2P\34\3\2\2\2QR\7-\2\2"+
		"R\36\3\2\2\2ST\7/\2\2T \3\2\2\2UV\7j\2\2VW\7c\2\2WX\7u\2\2XY\7c\2\2YZ"+
		"\7t\2\2Z[\7f\2\2[\"\3\2\2\2\\]\7*\2\2]$\3\2\2\2^_\7+\2\2_&\3\2\2\2`i\7"+
		"\62\2\2ae\t\2\2\2bd\t\3\2\2cb\3\2\2\2dg\3\2\2\2ec\3\2\2\2ef\3\2\2\2fi"+
		"\3\2\2\2ge\3\2\2\2h`\3\2\2\2ha\3\2\2\2i(\3\2\2\2jl\t\4\2\2kj\3\2\2\2l"+
		"m\3\2\2\2mk\3\2\2\2mn\3\2\2\2no\3\2\2\2op\b\25\2\2p*\3\2\2\2\6\2ehm\3"+
		"\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}