package logoparsing;

import javafx.scene.Group;

import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.ParseTreeProperty;

import logogui.Log;
import logogui.Traceur;
import logoparsing.LogoParser.AvContext;
import logoparsing.LogoParser.BcContext;
import logoparsing.LogoParser.FccContext;
import logoparsing.LogoParser.FposContext;
import logoparsing.LogoParser.LcContext;
import logoparsing.LogoParser.ReContext;
import logoparsing.LogoParser.TdContext;
import logoparsing.LogoParser.TgContext;
import logoparsing.LogoParser.VeContext;

public class LogoTreeVisitor extends LogoBaseVisitor<Integer> {
	Traceur traceur;
	ParseTreeProperty<Integer> atts = new ParseTreeProperty<Integer>();

	public LogoTreeVisitor() {
		super();
	}
	public void initialize(Group g) {
	      traceur = new Traceur();
	      traceur.setGraphics(g);
    }
	public void setAttValue(ParseTree node, int value) { 
		atts.put(node, value);
	}
	public int getAttValue(ParseTree node) { return atts.get(node); }
	@Override
	public Integer visitAv(AvContext ctx) {
		visitChildren(ctx);
		String intText = ctx.INT().getText(); 
		setAttValue(ctx.INT(), Integer.valueOf(intText));
		traceur.avance(getAttValue(ctx.INT()));
		Log.appendnl("visitAv");
		return 0;
	}
	@Override
	public Integer visitTd(TdContext ctx) {
		visitChildren(ctx);
		String intText = ctx.INT().getText(); 
		setAttValue(ctx.INT(), Integer.valueOf(intText));
		traceur.td(getAttValue(ctx.INT()));
		Log.append("visitTd\n" );
		return 0;
	}
	@Override
	public Integer visitTg(TgContext ctx) {
		visitChildren(ctx);
		String intText = ctx.INT().getText(); 
		setAttValue(ctx.INT(), Integer.valueOf(intText));
		traceur.tg(getAttValue(ctx.INT()));
		Log.append("visitTg\n" );
		return 0;
	}
	@Override
	public Integer visitLc(LcContext ctx) {
		visitChildren(ctx);
		traceur.lc();
		Log.append("visitLc\n" );
		return 0;
	}
	@Override
	public Integer visitBc(BcContext ctx) {
		visitChildren(ctx);
		traceur.bc();
		Log.append("visitBc\n" );
		return 0;
	}
	@Override
	public Integer visitVe(VeContext ctx) {
		visitChildren(ctx);
		traceur.ve();
		Log.append("visitVe\n" );
		return 0;
	}
	
	@Override
	public Integer visitRe(ReContext ctx) {
		visitChildren(ctx);
		String intText = ctx.INT().getText(); 
		setAttValue(ctx.INT(), Integer.valueOf(intText));
		traceur.re(getAttValue(ctx.INT()));
		Log.appendnl("visitRe");
		return 0;
	}
	@Override
	public Integer visitFpos(FposContext ctx) {
		visitChildren(ctx);
		String intText0 = ctx.INT(0).getText(); 
		setAttValue(ctx.INT(0), Integer.valueOf(intText0));
		String intText1 = ctx.INT(1).getText(); 
		setAttValue(ctx.INT(1), Integer.valueOf(intText1));
		traceur.fpos(getAttValue(ctx.INT(0)), getAttValue(ctx.INT(1)));
		Log.appendnl("visitFpos");
		return 0;
	}
	@Override
	public Integer visitFcc(FccContext ctx) {
		visitChildren(ctx);
		String intText = ctx.INT().getText(); 
		setAttValue(ctx.INT(), Integer.valueOf(intText));
		traceur.fcc(getAttValue(ctx.INT()));
		Log.append("visitFcc\n" );
		return 0;
	}
	
}
