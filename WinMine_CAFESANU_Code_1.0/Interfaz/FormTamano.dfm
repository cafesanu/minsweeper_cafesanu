object FormTam: TFormTam
  Left = 608
  Top = 343
  BorderStyle = bsDialog
  Caption = 'Parsonalizar Tamaño'
  ClientHeight = 73
  ClientWidth = 204
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 21
    Height = 13
    Caption = 'Alto:'
  end
  object Label2: TLabel
    Left = 8
    Top = 32
    Width = 34
    Height = 13
    Caption = 'Ancho:'
  end
  object edtFils: TEdit
    Left = 48
    Top = 8
    Width = 41
    Height = 21
    TabOrder = 0
  end
  object edtCols: TEdit
    Left = 48
    Top = 32
    Width = 41
    Height = 21
    TabOrder = 1
    OnKeyUp = edtColsKeyUp
  end
  object Button1: TButton
    Left = 112
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 112
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 3
    OnClick = Button2Click
  end
end
