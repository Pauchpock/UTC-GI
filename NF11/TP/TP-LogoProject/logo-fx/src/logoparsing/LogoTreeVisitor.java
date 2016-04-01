package logoparsing;

import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

import javafx.scene.Group;

import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.ParseTreeProperty;

import logogui.Log;
import logogui.Traceur;
import logoparsing.LogoParser.ArouleContext;
import logoparsing.LogoParser.AvContext;
import logoparsing.LogoParser.BcContext;
import logoparsing.LogoParser.FccContext;
import logoparsing.LogoParser.FposContext;
import logoparsing.LogoParser.HazContext;
import logoparsing.LogoParser.IntContext;
import logoparsing.LogoParser.LcContext;
import logoparsing.LogoParser.MutlContext;
import logoparsing.LogoParser.ParentheseContext;
import logoparsing.LogoParser.ReContext;
import logoparsing.LogoParser.SumContext;
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
	@Override
	public Integer visitHaz(HazContext ctx) {
		visitChildren(ctx);
		setAttValue(ctx, ThreadLocalRandom.current().nextInt(0, getAttValue(ctx.exp()) + 1));
		return 0;
	}
	public int getAttValue(ParseTree node) {
		return atts.get(node);
	}
	@Override
	public Integer visitAv(AvContext ctx) {
		visitChildren(ctx);
		traceur.avance(getAttValue(ctx.exp()));
		Log.appendnl("visitAv");
		return 0;
	}
	@Override
	public Integer visitTd(TdContext ctx) {
		visitChildren(ctx);
		traceur.td(getAttValue(ctx.exp()));
		Log.append("visitTd\n" );
		return 0;
	}
	@Override
	public Integer visitTg(TgContext ctx) {
		visitChildren(ctx);
		traceur.tg(getAttValue(ctx.exp()));
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
		traceur.re(getAttValue(ctx.exp()));
		Log.appendnl("visitRe");
		return 0;
	}
	@Override
	public Integer visitFpos(FposContext ctx) {
		visitChildren(ctx);
		traceur.fpos(getAttValue(ctx.exp(0)), getAttValue(ctx.exp(1)));
		Log.appendnl("visitFpos");
		return 0;
	}
	@Override
	public Integer visitFcc(FccContext ctx) {
		visitChildren(ctx);
		traceur.fcc(getAttValue(ctx.exp()));
		Log.append("visitFcc\n" );
		return 0;
	}
	@Override
	public Integer visitMutl(MutlContext ctx) {
		visitChildren(ctx);
		int left = getAttValue(ctx.exp(0));
		int right = getAttValue(ctx.exp(1));
		setAttValue(ctx, ctx.getChild(1).getText().equals("*") ?
			left * right : left / right);
		return 0;
	}
	@Override
	public Integer visitSum(SumContext ctx) {
		visitChildren(ctx);
		int left = getAttValue(ctx.exp(0)); // .exp() contient le seul fils expression si unique, sinon faire .exp(x)
		int right = getAttValue(ctx.exp(1));
		setAttValue(ctx, ctx.getChild(1).getText().equals("+") ?
			left + right : left - right);
		return 0;
	}
	
	@Override
	public Integer visitInt(IntContext ctx) {
		visitChildren(ctx);
		String intText = ctx.INT().getText();
		setAttValue(ctx, Integer.valueOf(intText));
		return 0;
	}
	
	@Override
	public Integer visitParenthese(ParentheseContext ctx) {
		visitChildren(ctx);
		setAttValue(ctx, getAttValue(ctx.exp()));
		return 0;
	}
	@Override
	public Integer visitAroule(ArouleContext ctx) {
		visit(ctx.atom());
		setAttValue(ctx, getAttValue(ctx.atom()));
		return 0;
	}
	
}
